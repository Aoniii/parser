#ifndef PARSER_H
# define PARSER_H

/**		Parser modes			*/
# define MODE_STRICT			0x0001
# define MODE_PERMISSIVE		0x0002

/**		Data types				*/
# define OPT_SHORT				0x0010
# define OPT_LONG				0x0020

/**		Flag types				*/
# define TYPE_BOOLEAN			0x0100
# define TYPE_INT				0x0200
# define TYPE_UINT				0x0400
# define TYPE_FLOAT				0x0800
# define TYPE_STRING			0x1000
# define TYPE_COUNT				0x2000
# define TYPE_CALLBACK			0x4000

/**		Masks					*/
# define MASK_MODE				0x000F
# define MASK_APPEARANCE		0x00F0
# define MASK_TYPE				0xFF00

/**		Parser struct			*/
typedef struct	s_option {
	char		short_opt;
	const char	*long_opt;
	int			flags;
	void		*value;
	const char	*help;
}				t_option;

/**		Callback fonctions		*/
typedef void	(*t_callback)(void);

/**		Errors					*/
typedef enum	e_parser_error {
	PARSER_SUCCESS = 0,
	ERR_UNKNOW_OPTION,
	ERR_MISSING_VALUE,
	ERR_INVALID_FORMAT,
	ERR_MALLOC_FAILED
}				t_parser_error;

/**		Fonctions				*/
char	**parser(int argc, char **argv, const t_option *options, int mode, t_parser_error *err);
void	assign(const t_option *options, char *value, t_parser_error *err);
void	cleaner(char **args);

#endif
