#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <stdbool.h>

/**	Parser modes		*/
# define MODE_POSIX		0x01
# define MODE_GNU		0x02

/**	Data types		*/
# define FLAG_SHORT		0x10
# define FLAG_LONG		0x20

/**	Flag value types	*/
# define FLAG_VALUE_REQUIRED	0x40
# define FLAG_VALUE_OPTIONAL	0x80

/**	Flag types		*/
# define FLAG_TYPE_INT		0x0100
# define FLAG_TYPE_STRING	0x0200
# define FLAG_TYPE_FLOAT	0x0400
# define FLAG_TYPE_BOOLEAN	0x0800

/**	Configuration		*/
# define PARSER_MODE		MODE_POSIX

#endif
