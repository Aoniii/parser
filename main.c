#include "parser.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int	main(int argc, char **argv) {
	t_parser_ctx	ctx;
	ctx.err = PARSER_SUCCESS;

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

	char	**args = parser(argc, argv, option, MODE_PERMISSIVE, &ctx);
	if (ctx.err != PARSER_SUCCESS) {
		//TODO: implement error handling
		cleaner(args);
		return (1);
	}

	debug(args, option);

	cleaner(args);
    return (0);
}
