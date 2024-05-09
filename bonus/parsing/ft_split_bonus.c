#include <stdlib.h>

static size_t	c_words(char *s, char c)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			++i;
			continue ;
		}
		while (s[i] && s[i] != c)
			++i;
		a++;
	}
	return (a);
}

char	**mem_free(char **a)
{
	size_t	i;

	i = 0;
	while (a[i])
		free(a[i++]);
	free(a);
	return (NULL);
}

static char	**split_str(char *s, char **a, char c, int k)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		j = i;
		while (s[j] != c && s[j])
			j++;
		a[k] = malloc(sizeof(char) * (j - i + 1));
		if (!a[k])
			return (mem_free(a));
		j = 0;
		while (s[i] && s[i] != c)
			a[k][j++] = s[i++];
		a[k++][j] = '\0';
	}
	a[k] = NULL;
	return (a);
}

char	**ft_split(char *s, char c)
{
	size_t	w;
	char	**a;

	if (!s)
		return (NULL);
	w = c_words(s, c);
	a = (char **)malloc(sizeof(char *) * (w + 1));
	if (!a)
		return (NULL);
	a = split_str(s, a, c, 0);
	return (a);
}
