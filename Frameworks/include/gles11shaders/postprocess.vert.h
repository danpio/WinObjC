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

#ifndef POSTPROCESS_VERT_H
#define POSTPROCESS_VERT_H

static const unsigned char postprocess_vert[] = {
    0x0a, 0x0a, 0x2f, 0x2f, 0x20, 0x41, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 
    0x74, 0x65, 0x73, 0x0a, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 
    0x65, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 
    0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x61, 0x74, 0x74, 0x72, 0x69, 
    0x62, 0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x61, 0x5f, 
    0x74, 0x65, 0x78, 0x43, 0x6f, 0x6f, 0x72, 0x64, 0x3b, 0x0a, 0x0a, 0x2f, 
    0x2f, 0x20, 0x56, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x73, 0x0a, 0x76, 
    0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 
    0x76, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6f, 0x72, 0x64, 0x3b, 0x0a, 
    0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x28, 0x29, 
    0x20, 0x0a, 0x7b, 0x0a, 0x09, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 
    0x74, 0x69, 0x6f, 0x6e, 0x20, 0x3d, 0x20, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 
    0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x65, 0x63, 
    0x74, 0x69, 0x6f, 0x6e, 0x4d, 0x61, 0x74, 0x72, 0x69, 0x78, 0x20, 0x2a, 
    0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 
    0x0a, 0x09, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6f, 0x72, 0x64, 
    0x20, 0x3d, 0x20, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x43, 0x6f, 0x6f, 0x72, 
    0x64, 0x3b, 0x09, 0x0a, 0x7d
};

#endif
