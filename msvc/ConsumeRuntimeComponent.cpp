//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#include <stdio.h>

#pragma comment(linker, "/INCLUDE:___refMTAThread")

extern "C"
{
	int __cdecl EbrDefaultXamlMain()
	{
		int main(int argc, char *argv[]);

		return main(0, NULL);
	}
	#pragma comment(linker, "/alternatename:?main@@YAHP$01$AAV?$Array@P$AAVString@Platform@@$00@Platform@@@Z=_EbrDefaultXamlMain")
}

#ifdef _M_ARM
#include <client.h>
int __cdecl main(::Platform::Array<::Platform::String^>^ args)
{
	EbrDefaultXamlMain();
}
#endif

