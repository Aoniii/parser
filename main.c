#include "parser.h"

int	main(int argc, char **argv) {
	(void) argc;
	(void) argv;

	int	count = 0;

	t_option option[] = {
		{
			.short_opt = 'c',
			.long_opt = "count",
			.flags = OPT_SHORT | OPT_LONG | OPT_VALUE_REQUIRED | TYPE_INT,
			.value = &count,
			.help = "example"
		},
		{0}
	};

	(void) option;
    return (0);
}

