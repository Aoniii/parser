#include <stdbool.h>

int	ft_atoi(const char *nptr) {
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	nptr--;
	while (*++nptr >= '0' && *nptr <= '9') {
		if (result == 0) result = *nptr - 48;
		else result = result * 10 + (*nptr - 48);
	}
	return (result * sign);
}

long long	ft_atoi_check(const char *nptr, bool *err) {
	long long	result = 0;
	int			sign = 1;
	bool		has_digits = false;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*nptr++ == '-')
			sign = -1;
	nptr--;
	while (*++nptr >= '0' && *nptr <= '9') {
		has_digits = true;

		if (result > 922337203685477580LL) {
            *err = true;
            return 0;
        }

		if (result == 0) result = *nptr - 48;
		else result = result * 10 + (*nptr - 48);
	}

	if (!has_digits || *nptr != '\0') {
		*err = true;
		return (0);
	}
	return (result * sign);
}

unsigned long long	ft_atoui_check(const char *nptr, bool *err) {
    unsigned long long result = 0;
    bool               has_digits = false;

    while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
        nptr++;

    if (*nptr == '+') {
        nptr++;
    } else if (*nptr == '-') {
        *err = true;
        return 0;
    }

    while (*nptr >= '0' && *nptr <= '9') {
        has_digits = true;

        if (result > 1844674407370955161ULL) {
            *err = true;
            return 0;
        }
        
        unsigned int digit = *nptr - '0';
        
        if (result == 1844674407370955161ULL && digit > 5) {
            *err = true;
            return 0;
        }

        result = result * 10 + digit;
        nptr++;
    }

    if (!has_digits || *nptr != '\0') {
        *err = true;
        return 0;
    }

    return result;
}

