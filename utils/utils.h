#ifndef UTILS_H
# define UTILS_H

#include <stddef.h>
#include <stdbool.h>

int					ft_atoi(const char *nptr);
long long			ft_atoi_check(const char *nptr, bool *err);
unsigned long long	ft_atoui_check(const char *nptr, bool *err);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif

