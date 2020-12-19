char *optarg;
int opterr = 1, optind = 1, optopt = 0;

/* Currently only POSIX/C locale. VERY unfinished. */
/* Replace character tests with locale independent character search functions. */
int
getopt(int argc, char *const argv[], const char *optstring)
{
	const char *optstr;
	static int indv;

	optind += !optind;
	if (optind >= argc)
		return -1;

	/*
	if (soptind != optind)
		soptind = optind, indv = 0;
	*/

	for (argv += optind; *argv; ++argv, ++optind) {
		if (**argv != '-') {
			indv = 0;
			continue;
		}

		if (*(*argv+1) == '-')
			return -1;
		for (optstr = optstring; *optstr && *(*argv+indv+1); ++optstr) {
			if (*optstr == ':')
				continue;
			if (*(*argv+indv+1) == *optstr) {
				if (*(optstr+1) == ':') {
					if (!*(*argv+indv+2)) {
						if (!argv[1])
							return optopt = *(*argv+indv+1), *optstring == ':' ? ':' : '?';
						optind += 2, optarg = argv[1], ++indv;
					} else
						++optind, optarg = (*argv+indv+2), indv = 0;
				} else
					++indv;

				return *(*argv+indv+1);
			}
		}
		if (!*optstr)
			return optopt = *(*argv+indv+1), '?';
		indv = 0;
	}

	return indv = 0, -1;
}
