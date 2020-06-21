#include "myString.h"

int strLen(char* s)
{
	char* ptr;
	for (ptr = s; *ptr; ptr++);
	return (ptr - s);
}

char* strCpy(char* dst, const char* src)
{
	char* dstPtr = dst;
	while ((*dstPtr++ = *src++) != '\0');
	return dst;
}

char* strnCpy(char* dst, const char* src, size_t n)
{
	char* dstPtr = dst;
	while (n > 0 && *src != '\0') {
		*dstPtr++ = *src++;
		--n;
	}
	*dstPtr = '\0';

	while (n > 0) {
		*dstPtr++ = '\0';
		--n;
	}
	return dst;
}

char* strCat(char* dst, const char* src)
{
	return strCpy(&dst[strLen(dst)], src);
}

char* strnCat(char* dst, const char* src, size_t n)
{
	if (n == 0) {
		return 0;
	}
	else {
		size_t dstLen = strLen(dst);
		size_t srcLen = strLen((char*)src);

		if (srcLen < n) {
			strCpy(&dst[dstLen], src);
		} else {
			strnCpy(&dst[dstLen], src, n);
		}
	}
	return dst;
}

int strCmp(char* s1, char* s2)
{
	for (; *s1 == *s2; s1++, s2++) {
		if (*s1 == '\0') {
			return 0;
		}
	}
	return ((*(const unsigned char*)s1 > *(const unsigned char*)s2) ? +1 : -1);
}

int strnCmp(char* s1, char* s2, size_t n)
{
	if (n == 0) {
		return 0;
	}
	else {
		for (; *s1 == *s2; --n, s1++, s2++) {
			if (*s1 != *s2) {
				return ((*(const unsigned char*)s1 > * (const unsigned char*)s2) ? +1 : -1);
			} else if (*s1 == '\0') {
				return 0;
			}
		}
	}
	return 0;
}
