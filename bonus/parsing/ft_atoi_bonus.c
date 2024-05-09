#include <string.h>
#include "parse_bonus.h"

int	ft_atoi(char *str)
{
	long long	a;
	int			i;

	i = 0;
	a = 0;
	if (ft_strlen(str) > 3)
		ft_print_err("color must be in range [0 ,255]\n", 0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		a = (a * 10) + ((str[i++] - '0'));
	if (a > 255)
		ft_print_err("color must be in range [0 ,255]\n", 0);
	return (a);
}

int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		++i;
	return (a[i] - b[i]);
}
