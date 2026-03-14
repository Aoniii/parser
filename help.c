#include "parser.h"
#include <stdio.h>

void	help(const t_parser_info info, const t_option *options) {
	printf("Help: %s\n", info.program);
	printf("Usage: %s\n", info.usage);
	printf("Description: %s\n", info.description);
	printf("Options:\n");
	for (const t_option *opt = options; opt->short_opt || opt->long_opt; opt++) {
		printf("  -%c, --%s\n", opt->short_opt, opt->long_opt);
		printf("    %s\n", opt->help);
	}
}

