#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new;
	int		i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		*s1 = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	while (*s2)
		new[i++] = *s2++;
	new[i] = '\0';
	free(s1);
	return (new);
}

int	ft_find_index(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_substr(char	*str, int s, int e)
{
	char	*new;
	int		i;

	if (s > e)
		return (NULL);
	new = malloc(sizeof(char) * (e - s + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (s <= e)
		new[i++] = str[s++];
	new[i] = '\0';
	return (new);
}

char	*ft_getline(char **s, char *buf)
{
	char	*new;
	char	*tmp;
	int		p;

	free(buf);
	if (!*s)
		return (NULL);
	p = ft_find_index(*s, '\n');
	if (p < 0)
	{
		new = ft_substr(*s, 0, ft_strlen(*s) - 1);
		free (*s);
		*s = NULL;
		return (new);
	}
	new = ft_substr(*s, 0, p);
	tmp = ft_substr(*s, p + 1, ft_strlen(*s) - 1);
	free(*s);
	*s = tmp;
	return (new);
}
