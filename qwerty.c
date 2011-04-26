// File name: Qwerty.c
// Description: Library for working with strings in C/C++ (source file)
// Author: Maxim Pestun
// Date: 2011.03.17
// Version: 1.1
// License: GNU GPL

#include "qwerty.h"

int FROM_NUMBER_TO_QWERTY_BUFFER_SIZE = 2048;

Qwerty newQwertyFromString(char *string) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT CREATE STRING FROM NULL\n");
		exit(1);
	}
	Qwerty result = (Qwerty)malloc(sizeof(Qwerty));
	int length = 0;
	int symbol = *(string);
	while(symbol != '\0') {
		length++;
		symbol = *(string + length);
	}
	result->str = (char*)malloc((length + 1) * sizeof(char));
	result->len = length;
	strncpy(result->str, string, length + 1);
	return result;
}

Qwerty newQwerty(char* string) {
	return newQwertyFromString(string);
}

Qwerty newQwertyFromQwerty(Qwerty string) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT CREATE STRING FROM NULL\n");
		exit(1);
	}
	Qwerty result = (Qwerty)malloc(sizeof(Qwerty));
	result->str = (char*)malloc((string->len + 1) * sizeof(char));
	result->len = string->len;
	strncpy(result->str, string->str, string->len + 1);
	return result;
}

Qwerty newQwertyFromInt(int number) {
	Qwerty result = (Qwerty)malloc(sizeof(Qwerty));
	char* string = (char*)malloc(FROM_NUMBER_TO_QWERTY_BUFFER_SIZE * sizeof(char));
	int length = sprintf(string, "%d", number);
	result->len = length;
	result->str = (char*)malloc((result->len + 1) * sizeof(char));
	strncpy(result->str, string, result->len + 1);
	return result;
}

Qwerty newQWertyFromLong(long number) {
	Qwerty result = (Qwerty)malloc(sizeof(Qwerty));
	char* string = (char*)malloc(FROM_NUMBER_TO_QWERTY_BUFFER_SIZE * sizeof(char));
	int length = sprintf(string, "%li", number);
	result->len = length;
	result->str = (char*)malloc((result->len + 1) * sizeof(char));
	strncpy(result->str, string, result->len + 1);
	return result;
}

Qwerty newQwertyFromDouble(double number) {
	Qwerty result = (Qwerty)malloc(sizeof(Qwerty));
	char* string = (char*)malloc(FROM_NUMBER_TO_QWERTY_BUFFER_SIZE * sizeof(char));
	int length = sprintf(string, "%f", number);
	result->len = length;
	result->str = (char*)malloc((result->len + 1) * sizeof(char));
	strncpy(result->str, string, result->len + 1);
	return result;
}

Qwerty printQwerty(Qwerty string) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT PRINT NULL STRING\n");
		exit(1);
	}
	printf("%s", string->str);
	return string;
}

Qwerty printlnQwerty(Qwerty string) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT PRINT NULL STRING\n");
		return NULL;
	}
	printf("%s\n", string->str);
	return string;
}

int lengthQwerty(Qwerty string) {
	if (string == NULL) {
		printf("QWERTY ERROR: UNKNOWN LENGTH OF NULL STRING\n");
		exit(1);
	}
	return string->len;
}

char* stringifyQwerty(Qwerty string) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT CONVERT NULL STRING\n");
		exit(1);
	}
	return string->str;
}

Qwerty concatQwerty(Qwerty string1, Qwerty string2) {
	if (string1 == NULL) {
		printf("QWERTY ERROR: CAN NOT CONCAT, VALUE ONE IS NULL\n");
		exit(1);
	} else if (string2 == NULL) {
		printf("QWERTY ERROR: CAN NOT CONCAT, VALUE TWO IS NULL\n");
		exit(1);
	}
	Qwerty result = (Qwerty)malloc(sizeof(Qwerty));
	result->len = string1->len + string2->len;
	result->str = (char*)malloc((result->len + 1) * sizeof(char));
	strncpy(result->str, string1->str, string1->len + 1);
	strncat(result->str, string2->str, string2->len + 1);
	return result;
}

Qwerty splitQwertyReturnLeft(Qwerty string, int position) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT SPLIT, STRING IS NULL\n");
		exit(1);
	}
	Qwerty result;
	result = (Qwerty)malloc(sizeof(Qwerty));
	if (position == 0 || (position < 0 && position <= -string->len)) {
		result->len = 0;
		result->str = (char*)malloc(sizeof(char));
		*(result->str) = '\0';
		return result;
	} else if (position > 0 && position <= string->len) {
		result->len = position;
	} else if (position > string->len) {
		result->len = string->len;
	} else if (position < 0 && position > -string->len) {
		result->len = string->len + position;
	}
	result->str = (char*)malloc((result->len + 1) * sizeof(char));
	strncpy(result->str, string->str, result->len);
	*(result->str + result->len) = '\0';
	return result;
}

Qwerty splitQwertyReturnRight(Qwerty string, int position) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT SPLIT, STRING IS NULL\n");
		exit(1);
	}
	Qwerty result;
	result = (Qwerty)malloc(sizeof(Qwerty));
	if (position == 0 || (position < 0 && position <= -string->len)) {
		result->len = string->len;
		result->str = (char*)malloc((result->len + 1) * sizeof(char));
		strncpy(result->str, string->str, result->len);
		*(result->str + result->len) = '\0';
		return result;
	} else if (position >= string->len) {
		result->len = 0;
		result->str = (char*)malloc(sizeof(char));
		*(result->str) = '\0';
		return result;
	} else if (position > 0) {
		result->len = string->len - position;
	} else if (position < 0) {
		result->len = -position;
		position = string->len + position;
	}
	result->str = (char*)malloc((result->len + 1) * sizeof(char));
	strncpy(result->str, string->str + position, result->len);
	*(result->str + result->len) = '\0';
	return result;
}

int findQwerty(Qwerty string, Qwerty part) {
	if (string == NULL) {
		printf("QWERTY ERROR: CAN NOT FIND IN NULL STRING\n");
		exit(1);
	}
	if (part == NULL) {
		printf("QWERTY ERROR: NULL STRING CAN NOT BE FOUND\n");
		exit(1);
	}
	char* found = strstr(string->str, part->str);
	if (found == NULL) {
		return -1;
	}
	return found - string->str;
}
