#include <stdlib.h>
#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	int		j;
	char	*new_string;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_string = malloc((len_s1 + len_s2 + 1) * sizeof(char ));
	if (!new_string)
		return (NULL);
	while (++i < len_s1)
		new_string[i] = s1[i];
	while ((i + j) < (len_s1 + len_s2))
	{
		new_string[i + j] = s2[j];
		j++;
	}
	new_string[i + j] = '\0';
	return (new_string);
}

static void	create_char(char *ch, unsigned int n, int size)
{
	if (n == 0)
		ch[size] = '0';
	while (n > 0)
	{
		ch[size--] = n % 10 + 48;
		n = n / 10;
	}
}

static int	count_num(unsigned int nbr)
{
	int	count;

	count = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*ch;

	if (n < 0)
		count = count_num(-n);
	else
		count = count_num(n);
	if (n < 0)
		count++;
	ch = malloc(count * sizeof(char ) + 1);
	if (!ch)
		return (NULL);
	ch[count--] = '\0';
	if (n < 0)
		ch[0] = '-';
	if (n < 0)
		create_char((ch), -n, count);
	else
		create_char((ch), n, count);
	return (ch);
}

int	has_wall(float x, float y, t_cub3d *cub)
{
	if (y < 0 || y >= (cub->par.size_map) * SQ_SIZE \
			|| x < 0 || \
				x >= (cub->par.size_col) * SQ_SIZE)
		return (0);
	return (cub->par.map[(int )(y / SQ_SIZE)][(int )(x / SQ_SIZE)] == '1');
}
