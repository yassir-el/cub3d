#include "parse_bonus.h"

char	**ft_split_identifier(char *line)
{
	char	**answer;
	t_vec	vec;
	int		i;

	answer = malloc(sizeof(char *) * 3);
	i = 0;
	while (line[i] && line[i] == ' ')
		++i;
	ft_memset(&vec, 0, sizeof(vec));
	while (line[i] && line[i] != ' ')
		ft_push_back(&vec, line[i++]);
	answer[0] = vec.string;
	while (line[i] && line[i] == ' ')
		++i;
	ft_memset(&vec, 0, sizeof(vec));
	while (line[i] && line[i] != '\n')
		ft_push_back(&vec, line[i++]);
	answer[1] = vec.string;
	answer[2] = NULL;
	return (answer);
}

void	ft_print_err(char *s, int pr)
{
	write(2, "Error\n", 6);
	if (!pr)
		write(2, s, ft_strlen(s));
	else
		perror("Error");
	exit (1);
}

char	*ft_strdup(char *s1)
{
	char	*a;
	size_t	i;

	i = ft_strlen(s1);
	a = (char *)malloc(sizeof(char) * (i + 1));
	if (!a)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
