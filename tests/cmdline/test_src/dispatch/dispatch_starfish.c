/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
 *
 * @APPLE_APACHE_LICENSE_HEADER_START@
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */

#include "config/config.h"

#include <dispatch/dispatch.h>
//#include "src/internal.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#if HAVE_TARGETCONDITIONALS_H
#include <TargetConditionals.h>
#endif

#include "dispatch_test.h"
#include <Windows.h>

#if TARGET_OS_EMBEDDED
#define COUNT	300ul
#define LAPS	10ul
#else
#define COUNT	1000ul
#define LAPS	10ul
#endif

static dispatch_queue_t queues[COUNT];
static size_t lap_count_down = LAPS;
static size_t count_down;
static uint64_t start;

static void do_test(void);

#define _dispatch_time_mach2nano(x) ((x))
#define _dispatch_absolute_time() GetTickCount64() * 1000000LL

static void
collect(void *context __attribute__((unused)))
{
	uint64_t delta;
	long double math;
	size_t i;

	if (--count_down) {
		return;
	}

	delta = _dispatch_absolute_time() - start;
	math = delta = _dispatch_time_mach2nano(delta);
	math /= COUNT * COUNT * 2ul + COUNT * 2ul;

	printf("lap: %ld\n", lap_count_down);
	printf("count: %lu\n", COUNT);
	printf("delta: %ju ns\n", (uintmax_t)delta);
	printf("math: %Lf ns / lap\n", math);

	for (i = 0; i < COUNT; i++) {
		dispatch_release(queues[i]);
	}

	// our malloc could be a lot better,
	// this result is really a malloc torture test
	test_long_less_than("Latency" , (unsigned long)math, 1000);

	if (--lap_count_down) {
		return do_test();
	}

	// give the threads some time to settle before test_stop() runs "leaks"
	// ...also note, this is a total cheat.   dispatch_after lets this
	// thread go idle, so dispatch cleans up the continuations cache.
	// Doign the "old style" sleep left that stuff around and leaks
	// took a LONG TIME to complete.   Long enough that the test harness
	// decided to kill us.
	dispatch_after_f(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), NULL, test_stop_after_delay);
}

static void
pong(void *context)
{
	dispatch_queue_t this_q = context;
	size_t replies = (size_t)dispatch_get_context(this_q);

	dispatch_set_context(this_q, (void *)--replies);
	if (!replies) {
		//printf("collect from: %s\n", dispatch_queue_get_label(dispatch_get_current_queue()));
		dispatch_async_f(dispatch_get_main_queue(), NULL, collect);
	}
}

static void
ping(void *context)
{
	dispatch_queue_t reply_q = context;

	dispatch_async_f(reply_q, reply_q, pong);
}

static void
start_node(void *context)
{
	dispatch_queue_t this_q = context;
	size_t i;

	dispatch_set_context(this_q, (void *)COUNT);

	for (i = 0; i < COUNT; i++) {
		dispatch_async_f(queues[i], this_q, ping);
	}
}

void
do_test(void)
{
	size_t i;

	count_down = COUNT;

	start = _dispatch_absolute_time();

	for (i = 0; i < COUNT; i++) {
		char buf[1000];
		_snprintf(buf, sizeof(buf), "com.example.starfish-node#%ld", i);
		queues[i] = dispatch_queue_create(buf, NULL);
		dispatch_suspend(queues[i]);
	}

	for (i = 0; i < COUNT; i++) {
		dispatch_async_f(queues[i], queues[i], start_node);
	}

	for (i = 0; i < COUNT; i++) {
		dispatch_resume(queues[i]);
	}
}

int
main(void)
{
    test_start("Dispatch Starfish");

	do_test();

	dispatch_main();
}
