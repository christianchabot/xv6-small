#include <stdio.h>

/* Include getopt.c to gcc rather than using #include unistd.h and -I switch */
extern int getopt(int, char *const [], const char *);
extern char *optarg;
extern int opterr, optind, optopt;

static const char _aarg[] = "-a", _barg[] = "-b", _carg[] = "-c";

/* Define argv tests here. */
#define Z (char *)
static char *const argv1[] = {
	"tmp", Z _aarg, Z _barg, Z _carg, 0
};

static char *const argv2[] = {
	"tmp", 0
};
#undef Z

#define ARGVSIZ(x) (sizeof(x)/sizeof(*x)-1)
struct {
	char *const *argv;
	char *opts;
	int argc;
} *ptr, test[] = {
	argv1, "abc", ARGVSIZ(argv1),
	argv2, "abc", ARGVSIZ(argv2)
};
#undef ARGVSIZ

int
main(int argc, char *argv[])
{
	int r;
	for (ptr = test; ptr < test + (sizeof(test)/sizeof(*test)); ++ptr) {
		char *const *aptr;
		printf("test %ld: getopt(..., \"%s\"): argv:", ptr - test, ptr->opts);
		for (aptr = ptr->argv+1; *aptr; ++aptr)
			printf(" %s,", *aptr);
		puts(" NULL");
		while ((r = getopt(ptr->argc, ptr->argv, ptr->opts)) != -1)
			switch (r) {
			case ':':
				printf("\tNot found \':\': %c\n", optopt); /* Should print the bad opt. */
				break;
			case '?':
				printf("\tNot found: \'?\': %c\n", optopt); /* Should print the bad opt. */
				break;
			default:
				printf("\t%s found: %c\n", *(ptr->argv+optind), r); /* Should print the opt found. */
				break;
			}
	}
	printf("tests complete.\n");
	return 0;
}
