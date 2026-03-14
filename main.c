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
	int	i = 0;

	t_option option[] = {
		CATEGORY("Category example"),
		{
			.short_opt	= 'i',
			.long_opt	= "int",
			.flags		= OPT_SHORT | OPT_LONG | TYPE_INT,
			.value		= &i,
			.help		= "Example of an integer variable"
		},
		{
			.short_opt	= 'h',
			.long_opt	= "help",
			.flags		= OPT_SHORT | OPT_LONG | OPT_CALLBACK_EXIT | OPT_HIDDEN_HELP | TYPE_CALLBACK,
			.value		= (void *)&(t_callback_info){
				.fn = callback_help,
				.data = (void *)&(t_help_data){
					.info = info,
					.options = option
				}
			},
			.help		= "Example of a callback"
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
