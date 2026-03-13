#include <stddef.h>

size_t	ft_strlen(const char *str) {
	size_t	size = 0;

	while (str[size])
		size++;
	return (size);
}

