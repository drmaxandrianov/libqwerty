// File name: Qwerty.h
// Description: Library for working with strings in C/C++ (header file)
// Author: Maxim Pestun
// Date: 2011.03.17
// Version: 1.1
// License: GNU GPL

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
