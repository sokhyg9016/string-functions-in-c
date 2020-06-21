# string-functions-in-c
Referred by apple open source

- [APPLE SOURCE BROWSER](https://opensource.apple.com/source/Libc/Libc-262/i386/gen/)
- [Apple source browser:other version](https://opensource.apple.com/source/Libc/Libc-262/ppc/gen/)

```
/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
/*
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

 /*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * The contents of this file constitute Original Code as defined in and
 * are subject to the Apple Public Source License Version 1.1 (the
 * "License").  You may not use this file except in compliance with the
 * License.  Please obtain a copy of the License at
 * http://www.apple.com/publicsource and read it before using this file.
 * 
 * This Original Code and all software distributed under the License are
 * distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */
```

## strcmp

```c
/*
 * Compare strings.
 */
int strcmp(s1, s2)
	register const char *s1, *s2;
{
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)--s2);
}

/* This routine should be optimized. */

/* ANSI sez:
 *   The `strcmp' function compares the string pointed to by `s1' to the
 *   string pointed to by `s2'.
 *   The `strcmp' function returns an integer greater than, equal to, or less
 *   than zero, according as the string pointed to by `s1' is greater than,
 *   equal to, or less than the string pointed to by `s2'.  [4.11.4.2]
 */
int strcmp(const char *s1, const char *s2)
{
    for ( ; *s1 == *s2; s1++, s2++)
	if (*s1 == '\0')
	    return 0;
    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
}

```

## strncmp

```c
int strncmp(s1, s2, n)
	register const char *s1, *s2; register size_t n;
{

	if (n == 0)
		return (0);
	do {
		if (*s1 != *s2++)
			return (*(unsigned char *)s1 - *(unsigned char *)--s2);
		if (*s1++ == 0)
			break;
	} while (--n != 0);
	return (0);
}

/* This routine should be optimized. */

/* ANSI sez:
 *   The `strncmp' function compares not more than `n' characters (characters
 *   that follow a null character are not compared) from the array pointed to
 *   by `s1' to the array pointed to by `s2'.
 *   The `strncmp' function returns an integer greater than, equal to, or less
 *   than zero, according as the possibly null-terminated array pointed to by
 *   `s1' is greater than, equal to, or less than the possibly null-terminated
 *   array pointed to by `s2'.  [4.11.4.4]
 */
int strncmp(const char *s1, const char *s2, size_t n)
{
    for ( ; n > 0; s1++, s2++, --n)
	if (*s1 != *s2)
	    return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : +1);
	else if (*s1 == '\0')
	    return 0;
    return 0;
}
```

## strlen

```c
size_t strlen(str)
	const char *str;
{
	register const char *s;

	for (s = str; *s; ++s);
	return(s - str);
}
```

## strcpy

```c
char * strcpy(to, from)
	register char *to;
	register const char *from;
{
	char *save = to;

	for (; *to = *from; ++from, ++to);
	return(save);
}

/* ANSI sez:
 *   The `strcpy' function copies the string pointed to by `s2' (including
 *   the terminating null character) into the array pointed to by `s1'.
 *   If copying takes place between objects that overlap, the behavior
 *   is undefined.
 *   The `strcpy' function returns the value of `s1'.  [4.11.2.3]
 */
char *strcpy(char *s1, const char *s2)
{
    char *s = s1;
    while ((*s++ = *s2++) != 0)
	;
    return (s1);
}
```

## strncpy

```c
/*
 * Copy src to dst, truncating or null-padding to always copy n bytes.
 * Return dst.
 */
char *
strncpy(dst, src, n)
	char *dst;
	const char *src;
	register size_t n;
{
	if (n != 0) {
		register char *d = dst;
		register const char *s = src;

		do {
			if ((*d++ = *s++) == 0) {
				/* NUL pad the remaining n-1 bytes */
				while (--n != 0)
					*d++ = 0;
				break;
			}
		} while (--n != 0);
	}
	return (dst);
}

/* ANSI sez:
 *   The `strncpy' function copies not more than `n' characters (characters
 *   that follow a null character are not copied) from the array pointed to
 *   by `s2' to the array pointed to by `s1'.  If copying takes place between
 *   objects that overlap, the behavior is undefined.
 *   If the array pointed to by `s2' is a string that is shorter than `n'
 *   characters, null characters are appended to the copy in the array
 *   pointed to by `s1', until `n' characters in all have been written.
 *   The `strncpy' function returns the value of `s1'.  [4.11.2.4]
 */
char *strncpy(char *s1, const char *s2, size_t n)
{
    char *s = s1;
    while (n > 0 && *s2 != '\0') {
	*s++ = *s2++;
	--n;
    }
    while (n > 0) {
	*s++ = '\0';
	--n;
    }
    return s1;
}
```

## strcat

```c
char *
strcat(s, append)
	register char *s;
	register const char *append;
{
	char *save = s;

	for (; *s; ++s);
	while (*s++ = *append++);
	return(save);
}

char *strcat(char *s1, const char *s2)
{
    strcpy(&s1[strlen(s1)], s2);
    return s1;
}
```

## strncat

```c
/*
 * Concatenate src on the end of dst.  At most strlen(dst)+n+1 bytes
 * are written at dst (at most n+1 bytes being appended).  Return dst.
 */
char *
strncat(dst, src, n)
	char *dst;
	const char *src;
	register size_t n;
{
	if (n != 0) {
		register char *d = dst;
		register const char *s = src;

		while (*d != 0)
			d++;
		do {
			if ((*d = *s++) == 0)
				break;
			d++;
		} while (--n != 0);
		*d = 0;
	}
	return (dst);
}

char *strncat(char *s1, const char *s2, size_t n)
{
    unsigned len1 = strlen(s1);
    unsigned len2 = strlen(s2);
    
    if (len2 < n) {
	strcpy(&s1[len1], s2);
    } else {
	strncpy(&s1[len1], s2, n);
	s1[len1 + n] = '\0';
    }
    return s1;
}
```
