#ifndef VEC_BONUS_H
# define VEC_BONUS_H

# include <stdlib.h>

typedef struct s_vec
{
	char	*string;
	int		size;
	int		i;
}	t_vec;

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;

t_list	*ft_new(char *data);
void	ft_push(t_list **head, t_list *node);

void	ft_push_back(t_vec *vec, char data);
void	ft_create_vec(t_vec *vec, int size);

void	ft_lstclear(t_list **head);
int		ft_lstsize(t_list *head);
char	**ft_split(char const *s, char c);
char	**mem_free(char **a);
int		ft_atoi(char *str);

#endif
