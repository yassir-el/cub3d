#include "parse_bonus.h"

void	ft_way_2_0(char **data, t_list **head)
{
	t_vec	vec;
	int		i;
	int		j;

	i = 0;
	while (data[++i])
	{
		j = 0;
		ft_memset(&vec, 0, sizeof(t_vec));
		while (data[i][j] && data[i][j] != '\n')
		{
			if (data[i][j] == ',')
			{
				if (vec.string)
					ft_push(head, ft_new(vec.string));
				ft_push(head, ft_new(ft_strdup(",")));
				ft_memset(&vec, 0, sizeof(t_vec));
			}
			else
				ft_push_back(&vec, data[i][j]);
			++j;
		}
		if (vec.string)
			ft_push(head, ft_new(vec.string));
	}
}

void	ft_check(t_list *head)
{
	int	n;

	if (ft_lstsize(head) != 6)
		ft_print_err("information not in correct places\n", 0);
	if (!ft_strcmp(head->next->data, ","))
		ft_print_err("the \',\' should not be first\n", 0);
	n = 0;
	while (head)
	{
		if (n % 2 && !ft_isdigit(head->data))
			ft_print_err("all characters should be digits\n", 0);
		else if (!ft_strcmp(head->data, ","))
		{
			if (!head->next || !ft_strcmp(head->next->data, ","))
				ft_print_err("\',\' should be followed by a number\n", 0);
		}
		n++;
		head = head->next;
	}	
}

int	ft_find(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_isdigit(char *s)
{
	while (*s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		s++;
	}
	return (1);
}
