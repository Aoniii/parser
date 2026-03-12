#ifndef PARSER_H
# define PARSER_H

/**		Parser modes			*/
# define MODE_STRICT			0x00000001
# define MODE_PERMISSIVE		0x00000002

/**		Data types				*/
# define OPT_SHORT				0x00000010
# define OPT_LONG				0x00000020

/**		Flag value types		*/
# define OPT_VALUE_REQUIRED		0x00000100
# define OPT_VALUE_OPTIONAL		0x00000200

/**		Flag types				*/
# define TYPE_NONE				0x00001000
# define TYPE_BOOLEAN			0x00002000
# define TYPE_INT				0x00004000
# define TYPE_UINT				0x00008000
# define TYPE_FLOAT				0x00010000
# define TYPE_STRING			0x00020000
# define TYPE_CALLBACK			0x00040000

/**		Special					*/
# define OPT_INCREMENT			0x00100000
# define OPT_STOP_PARSING		0x00200000

/**		Masks					*/
# define MASK_MODE				0x0000000F
# define MASK_APPEARANCE		0x000000F0
# define MASK_VALUE_REQ			0x00000F00
# define MASK_TYPE				0x000FF000
# define MASK_SPECIAL			0x00F00000

/**		Parser struct			*/
typedef struct	s_option {
	char		short_opt;
	const char	*long_opt;
	int			flags;
	void		*value;
	const char	*help;
}				t_option;

/**		Errors					*/
typedef enum	e_parser_error {
	PARSER_SUCCESS = 0,
	ERR_UNKNOW_OPTION,
	ERR_MISSING_VALUE,
	ERR_INVALID_FORMAT,
	ERR_MALLOC_FAILED
}				t_parser_error;

#endif
