#include "parser.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int	main(int argc, char **argv) {
	t_parser_error	err = PARSER_SUCCESS;

	int	count = 0;

	t_option option[] = {
		{
			.short_opt = 'c',
			.long_opt = "count",
			.flags = OPT_SHORT | OPT_LONG | TYPE_INT,
			.value = &count,
			.help = "Example of a counter variable"
		},
		{0}
	};

	char	**args = parser(argc, argv, option, MODE_PERMISSIVE, &err);
	if (err != PARSER_SUCCESS) {
		//TODO: implement error handling
		cleaner(args);
		return (1);
	}

	printf("Value of count: %d\n", count);
	
	int	index = 0;
	while (args[index]) {
		printf("Argument: %s\n", args[index]);
		index++;
	}

	cleaner(args);
    return (0);
}
