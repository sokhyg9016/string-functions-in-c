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

