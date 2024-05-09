#include "vec.h"

void	ft_push_back(t_vec *vec, char data)
{
	char	*new;
	int		j;

	if (vec->i + 1 >= vec->size)
	{
		if (!vec->size)
			vec->size = 2;
		new = malloc(sizeof(char) * (vec->size * 2));
		vec->size *= 2;
		j = 0;
		while (vec->string && vec->string[j])
		{
			new[j] = vec->string[j];
			j++;
		}
		new[j++] = data;
		new[j] = '\0';
		free (vec->string);
		vec->string = new;
		vec->i = j;
		return ;
	}
	vec->string[vec->i++] = data;
	vec->string[vec->i] = '\0';
}

t_list	*ft_new(char *data)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new || !data)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *head)
{
	int	i;

	i = 0;
	while (head)
	{
		head = head->next;
		++i;
	}
	return (i);
}

void	ft_push(t_list **head, t_list *node)
{
	t_list	*t;

	if (!*head)
	{
		*head = node;
		return ;
	}
	t = *head;
	while (t->next)
		t = t->next;
	t->next = node;
}

void	ft_lstclear(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = temp->next;
		free(temp->data);
		free(temp);
	}
}
