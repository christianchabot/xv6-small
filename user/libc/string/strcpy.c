char *
strcpy(char *restrict s1, const char *restrict s2)
{
	register char *r = s1;
	while ((void) 0, *s1 = *s2) /* Leave like this for now. */
		++s1, ++s2;
	return r;
}
