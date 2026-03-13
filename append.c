#include "parser.h"
#include <stdlib.h>
#include <string.h>

char	**append_arg(char **args, char *new_arg, t_parser_error *err) {
	int	size = 0;
	if (args)
		while (args[size])
			size++;

	char	**new = realloc(args, sizeof(char *) * (size + 2));
	if (!new) {
		*err = ERR_MALLOC_FAILED;
		return (args);
	}

	new[size] = strdup(new_arg);
	if (!new[size]) {
		*err = ERR_MALLOC_FAILED;
		new[size] = NULL;
		return (new);
	}
	new[size + 1] = NULL;
	
	return (new);
}

