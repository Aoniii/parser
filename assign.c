#include "parser.h"
#include "utils/utils.h"

typedef void		(*t_assign_fn)(const t_option *options, char *value, t_parser_error *err);

typedef struct		s_assign_entry {
	int				type_flag;
	t_assign_fn		fn;
}					t_assign_entry;

static void	assign_boolean(const t_option *options, char *value, t_parser_error *err);
static void	assign_int(const t_option *options, char *value, t_parser_error *err);
static void	assign_uint(const t_option *options, char *value, t_parser_error *err);
static void	assign_float(const t_option *options, char *value, t_parser_error *err);
static void	assign_string(const t_option *options, char *value, t_parser_error *err);
static void	assign_count(const t_option *options, char *value, t_parser_error *err);
static void	assign_callback(const t_option *options, char *value, t_parser_error *err);

/**
 * @brief Assigns an option's value to its typed target.
 * * Based on the type flags (TYPE_*), this function converts the
 *   string value and writes the result into options->value, or
 *   triggers a specific behavior (counter, callback, boolean).
 * * Supported types:
 *   - TYPE_BOOLEAN : sets the target value to true, ignores value.
 *   - TYPE_INT     : parses a signed integer.
 *   - TYPE_UINT    : parses an unsigned integer.
 *   - TYPE_FLOAT   : parses a floating point number.
 *   - TYPE_STRING  : stores the raw pointer to value.
 *   - TYPE_COUNT   : increments an integer counter.
 *   - TYPE_CALLBACK: calls the function stored in options->value.
 * * On parsing error or missing value, err is updated with the
 *   appropriate error code (ERR_MISSING_VALUE, ERR_INVALID_FORMAT, ...).
 *
 * @param options  Pointer to the option description (t_option).
 * @param value    Raw string associated with the option (or NULL if none).
 * @param err      Pointer to the parser error code.
 */
void	assign(const t_option *options, char *value, t_parser_error *err) {
	if (!options || !options->value)
		return;

	const t_assign_entry	assign_table[] = {
		{ TYPE_BOOLEAN,  assign_boolean },
		{ TYPE_INT,      assign_int },
		{ TYPE_UINT,     assign_uint },
		{ TYPE_FLOAT,    assign_float },
		{ TYPE_STRING,   assign_string },
		{ TYPE_COUNT,    assign_count },
		{ TYPE_CALLBACK, assign_callback },
		{ 0, NULL }
	};

	int	index = 0;
	while (assign_table[index].type_flag) {
		if (options->flags & assign_table[index].type_flag) {
			assign_table[index].fn(options, value, err);
			return;
		}
		index++;
	}
}

static void	assign_boolean(const t_option *options, char *value, t_parser_error *err) {
	(void)value;
	(void)err;
	*((bool *)options->value) = true;
}

static void	assign_int(const t_option *options, char *value, t_parser_error *err) {
	if (!value) {
		*err = ERR_MISSING_VALUE;
		return;
	}

	bool		check = false;
	long long	result = ft_atoi_check(value, &check);

	if (check) {
		*err = ERR_INVALID_FORMAT;
		return;
	}

	*((long long *) options->value) = result;
}

static void	assign_uint(const t_option *options, char *value, t_parser_error *err) {
	if (!value) {
		*err = ERR_MISSING_VALUE;
		return;
	}

	bool				check = false;
	unsigned long long	result = ft_atoui_check(value, &check);

	if (check) {
		*err = ERR_INVALID_FORMAT;
		return;
	}

	*((unsigned long long *) options->value) = result;
}

static void	assign_float(const t_option *options, char *value, t_parser_error *err) {
	//TODO: implement
	(void)options;
	(void)value;
	(void)err;
}

static void	assign_string(const t_option *options, char *value, t_parser_error *err) {
	if (!value) {
		*err = ERR_MISSING_VALUE;
		return;
	}

	*((char **)options->value) = value;
}

static void	assign_count(const t_option *options, char *value, t_parser_error *err) {
	(void)value;
	(void)err;
	(*((int *)options->value))++;
}

static void	assign_callback(const t_option *options, char *value, t_parser_error *err) {
	(void)value;
	(void)err;
	t_callback func = (t_callback)options->value;
	func();
}
