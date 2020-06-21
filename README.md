# string-functions-in-c
Referred by apple open source

> [APPLE SOURCE BROWSER](https://opensource.apple.com/source/Libc/Libc-262/i386/gen/)

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
```
