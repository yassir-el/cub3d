#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *s);
char	*ft_join(char *s1, char *s2);
int		ft_find_index(char *s, char c);
char	*ft_substr(char	*str, int s, int e);
char	*ft_getline(char **s, char *buf);

#endif
