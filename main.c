#include "parser.h"
#include <stdbool.h>
#include <stddef.h>

int	main(int argc, char **argv) {
	/**		Error			*/
	t_parser_ctx	ctx;
	ctx.err = PARSER_SUCCESS;

	/**		Information		*/
	t_parser_info	info = {
		.program		= argv[0],
		.usage			= "[Example...] Example ...",
		.description	= "Description example"
	};

	/**		Options			*/
	int	count = 0;

	t_option option[] = {
		CATEGORY("Category example"),
		{
			.short_opt	= 'c',
			.long_opt	= "count",
			.flags		= OPT_SHORT | OPT_LONG | TYPE_INT,
			.value		= &count,
			.help		= "Example of a counter variable"
		},
		{
			.short_opt	= 'h',
			.long_opt	= "help",
			.flags		= OPT_SHORT | OPT_LONG | TYPE_CALLBACK,
			.value		= help,
			.help		= ""
		},
		{0}
	};

	/**		Parsing			*/
	char	**args = parser(argc, argv, option, MODE_PERMISSIVE, &ctx);
	if (ctx.err != PARSER_SUCCESS) {
		error(info.program, &ctx);
		cleaner(args);
		return (1);
	}

	/**		Execution		*/
	debug(args, option);

	cleaner(args);
    return (0);
}
