#ifndef __myString_H__
#define __myString_H__

#include <stdio.h>
#define STR_MAX 100

int strLen(char* s);

char* strCpy(char* dst, const char* src);
char* strnCpy(char* dst, const char* src, size_t n);

char* strCat(char* dst, const char* src);
char* strnCat(char* dst, const char* src, size_t n);

int strCmp(char* s1, char* s2);
int strnCmp(char* s1, char* s2, size_t n);
#endif