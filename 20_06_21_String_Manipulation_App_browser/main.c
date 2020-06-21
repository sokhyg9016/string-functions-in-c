#define __CRT_SECURE_NO_WARNINGS
#include "myString.h"

int main(void)
{
	char myStr[STR_MAX];
	char tmp[STR_MAX];

	// strCpy (+ strnCpy) & strLen test
	strCpy(myStr, "Hello World!");
	printf("Output of strCpy: %s\n", myStr);
	printf("Output of strLen: %ld\n\n", strLen(myStr));

	strnCpy(tmp, myStr, 10);
	printf("Output of strCpy: %s\n", tmp);
	printf("Output of strLen: %ld\n\n", strLen(tmp));

	// strcmp & strncmp
	printf("Output of strCmp: %d\n", strCmp(myStr, tmp));
	printf("Output of strCmp: %d\n\n", strnCmp(myStr, tmp, 10));

	// strCat & strnCat
	//strCat(myStr, tmp);
	strnCat(myStr, tmp, 8);
	printf("Output of strCat: %s\n", myStr);
	printf("Output of strLen: %ld\n\n", strLen(myStr));


	return 0;
}