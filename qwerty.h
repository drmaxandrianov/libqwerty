// The MIT License (MIT)

// Copyright (c) 2013 by Maxim Pestun

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef QWERTY_H
#define QWERTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Variable used during convertion from number to string,
// it means, that result string with number should be shorter
// then this number.
extern int FROM_NUMBER_TO_QWERTY_BUFFER_SIZE;


// New type for storing strings
typedef struct {
	char* str;    // pointer to the string
	int   len;    // number of letters including '\0'
} *Qwerty;


// Creates new Qwerty from ordinary string
Qwerty newQwerty(char* string);

// Creates new Qwerty from ordinary string
Qwerty newQwertyFromString(char* string);

// Creates new Qwerty from Qwerty
Qwerty newQwertyFromQwerty(Qwerty string);

// Creates new Qwerty from Integer
Qwerty newQwertyFromInt(int number);

// Creates new Qwerty from Long Integer
Qwerty newQWertyFromLong(long number);

// Creates new Qwerty from Double
Qwerty newQwertyFromDouble(double number);

// Prints Qwerty and returns it
Qwerty printQwerty(Qwerty string);

// Prints Qwerty with new line at the end and returns it
Qwerty printlnQwerty(Qwerty string);

// Returns length of Qwerty excluding '\0'
int lengthQwerty(Qwerty string);

// Returns ordinary string, created from Qwerty
char* stringifyQwerty(Qwerty string);

// Returns concateneted Qwerty
Qwerty concatQwerty(Qwerty string1, Qwerty string2);

// Splits Qwerty with position and returns left part,
// values below zero can be used too
Qwerty splitQwertyReturnLeft(Qwerty string, int position);

// Splits Qwerty with position and returns right part,
// values below zero can be used too
Qwerty splitQwertyReturnRight(Qwerty string, int position);

// Returns index of first match, if not found returns -1
int findQwerty(Qwerty string, Qwerty part);

#endif
