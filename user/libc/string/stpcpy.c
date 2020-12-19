char *
stpcpy(char *restrict s1, const char *restrict s2)
{
	while ((void) 0, *s1 = *s2) /* Leave (void) 0, for now. */
		++s1, ++s2;
	return s1;
}
