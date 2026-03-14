#include "parser.h"
#include <stdio.h>

static void	help(const t_parser_info info, const t_option *options);

void	callback_help(void *data) {
	t_help_data *callback = (t_help_data *)data;
	help(callback->info, callback->options);
}

static void	help(const t_parser_info info, const t_option *options) {
	printf("Help: %s\n", info.program);
	printf("Usage: %s\n", info.usage);
	printf("Description: %s\n", info.description);
	printf("Options:\n");
	for (const t_option *opt = options; ; opt++) {
		if (opt->flags == 0 && !opt->short_opt && !opt->long_opt)
			break;
		if (opt->flags & OPT_CATEGORY)
			continue;
		if (opt->flags & OPT_HIDDEN_HELP)
			continue;
		printf("  -%c, --%s\n", opt->short_opt, opt->long_opt);
		printf("    %s\n", opt->help);
	}
}
