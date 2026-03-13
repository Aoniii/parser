#include "parser.h"
#include <stdbool.h>
#include <stddef.h>

int	main(int argc, char **argv) {
	t_parser_error	err = PARSER_SUCCESS;

	int	count = 0;

	t_option option[] = {
		{
			.short_opt = 'c',
			.long_opt = "count",
			.flags = OPT_SHORT | OPT_LONG | TYPE_INT,
			.value = &count,
			.help = "example"
		},
		{0}
	};

	char	**args = parser(argc, argv, option, MODE_PERMISSIVE, &err);
	if (err != PARSER_SUCCESS) {
		//TODO: implement error handling
		cleaner(args);
		return (1);
	}

	//TODO: implement parsing information printing
	cleaner(args);
    return (0);
}
