#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*a;
	char		*buf;
	int			b;

	if (BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	b = read(fd, buf, BUFFER_SIZE);
	while (b > 0)
	{
		buf[b] = '\0';
		a = ft_join(a, buf);
		if (!a)
		{
			free(buf);
			return (NULL);
		}
		if (ft_find_index(a, '\n') > -1)
			return (ft_getline(&a, buf));
		b = read(fd, buf, BUFFER_SIZE);
	}
	return (ft_getline(&a, buf));
}
