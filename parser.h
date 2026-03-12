#ifndef PARSER_H
# define PARSER_H

/**		Parser modes			*/
# define MODE_STRICT			0x01
# define MODE_PERMISSIVE		0x02

/**		Data types				*/
# define OPT_SHORT				0x10
# define OPT_LONG				0x20

/**		Flag value types		*/
# define OPT_VALUE_REQUIRED		0x40
# define OPT_VALUE_OPTIONAL		0x80

/**		Flag types				*/
# define TYPE_NONE				0x0000
# define TYPE_BOOLEAN			0x0100
# define TYPE_INT				0x0200
# define TYPE_UINT				0x0400
# define TYPE_FLOAT				0x0800
# define TYPE_STRING			0x1000
# define TYPE_CALLBACK			0x2000

/**		Special					*/
# define OPT_INCREMENT			0x010000
# define OPT_STOP_PARSING		0x020000

/**		Parser struct			*/
typedef struct	s_option {
	char		short_opt;
	const char	*long_opt;
	int			flags;
	void		*value;
	const char	*help;
}				t_option;

typedef struct	s_parser {
	t_option	*options;
	int			opt_count;
	int			mode;
	char		**args;
	int			args_count;
}				t_parser;

#endif
