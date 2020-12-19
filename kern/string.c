void *
memcpy(void *s1, const void *s2, unsigned long int n)
{
	register char *p1 = s1;
	register const char *p2 = s2;
	for (; n; --n)
		*p1++ = *p2++;
	return s1;
}

int
memcmp(const void *s1, const void *s2, unsigned long int n)
{
	register const char *e = s1 + n, *p1 = s1, *p2 = s2;
	for (; p1 < e; ++p1, ++p2)
		if (*(unsigned char *) p1 != *(unsigned char *) p2)
			return *(unsigned char *) p1 - *(unsigned char *) p2;
	return 0;
}

void *
memmove(void *s1, const void *s2, unsigned long int n)
{
	register char *p1 = s1;
	register const char *p2 = s2;
	if (p2 >= p1)
		for (; n; --n)
			*p1++ = *p2++;
	else
		for (p1 += n, p2 += n; n; --n)
			*--p1 = *--p2;
	return s1;
}

/* Used lots should try to vector or use word length. */
void *
memset(void *s, int c, unsigned long int n)
{
	register char *p = s;
	for (; n; --n)
		*p++ = (unsigned) c;
	return s;
}

int
strncmp(register const char *s1, register const char *s2, unsigned long int n)
{
	register const char *e = s1 + n;
	for (; s1 < e && *s1; ++s1, ++s2)
		if (*(unsigned char *) s1 != *(unsigned char *) s2)
			return *(unsigned char *) s1 - *(unsigned char *) s2;
	return s1 < e ? *(unsigned char *) s1 - *(unsigned char *) s2 : 0;
}

char *
strncpy(char *s1, const char *s2, unsigned long int n)
{
	register char *p1 = s1;
	register const char *p2 = s2;
	for (; n; --n)
		if ((void) 0, *p1++ = *p2) /* Leave (void) 0, for now. */
			++p2;
	return s1;
}

/* Like strncpy but guaranteed to NUL-terminate. */
char *
safestrcpy(char *s1, const char *s2, unsigned long int n)
{
	register char *p1 = s1;
	register const char *e = s1 + n, *p2 = s2;
	if (n) {
		while (p1 < e && (*p1 = *p2))
			++p1, ++p2;
		return *p1 = 0, s1;
	}
	return s1;
}

unsigned long int
strlen(const char *s)
{
	register const char *p = s;
	while (*p)
		++p;
	return p - s;
}
