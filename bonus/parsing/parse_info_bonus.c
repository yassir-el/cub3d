#include "parse_bonus.h"

void	parse_info(t_list **head, t_parse *par_info)
{
	int		counter;
	char	bool_[6];

	counter = 6;
	ft_memset(bool_, 0, 6);
	while (counter && (*head))
	{
		if ((*head)->data[0] != '\n')
		{
			ft_identifier_parse((*head)->data, par_info, bool_);
			counter--;
		}
		(*head) = (*head)->next;
	}
}

void	ft_identifier_parse(char *line, t_parse *par, char *bool_)
{
	char	**data;
	int		i;

	data = ft_split(line, ' ');
	if (!data || !data[0])
		ft_print_err("something wrong with the file\n", 0);
	i = 0;
	ft_identifier(data[0], bool_);
	if (data[0][0] != 'F' && data[0][0] != 'C')
	{
		mem_free(data);
		data = ft_split_identifier(line);
		ft_way(data, par);
	}
	else
		ft_way_2(data, par);
	mem_free(data);
}

void	ft_identifier(char *s, char *bool_)
{
	if (!ft_strcmp(s, "NO") && !bool_[0])
		bool_[0] = 1;
	else if (!ft_strcmp(s, "SO") && !bool_[1])
		bool_[1] = 1;
	else if (!ft_strcmp(s, "WE") && !bool_[2])
		bool_[2] = 1;
	else if (!ft_strcmp(s, "EA") && !bool_[3])
		bool_[3] = 1;
	else if (!ft_strcmp(s, "F") && !bool_[4])
		bool_[4] = 1;
	else if (!ft_strcmp(s, "C") && !bool_[5])
		bool_[5] = 1;
	else
		ft_print_err("something wrow with the identifier\n", 0);
}

void	ft_way(char **data, t_parse *par)
{
	int		i;
	char	c;

	i = 0;
	while (data[i])
		++i;
	if (i != 2)
	{
		if (i < 2 || ft_strcmp(data[2], "\n"))
			ft_print_err("data of identifier not found\n", 0);
	}
	c = data[0][0];
	if (c == 'N')
		par->north_path = ft_strdup(data[1]);
	else if (c == 'S')
		par->south_path = ft_strdup(data[1]);
	else if (c == 'W')
		par->west_path = ft_strdup(data[1]);
	else if (c == 'E')
		par->east_path = ft_strdup(data[1]);
}

void	ft_way_2(char **data, t_parse *par)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	head = NULL;
	ft_push(&head, ft_new(ft_strdup(data[0])));
	if (!data[1])
		ft_print_err("data of identifier not found\n", 0);
	ft_way_2_0(data, &head);
	ft_check(head);
	tmp = head->next;
	i = 0;
	while (tmp)
	{
		if (ft_isdigit(tmp->data))
		{
			if (head->data[0] == 'F')
				par->floor_color[i++] = ft_atoi(tmp->data);
			else
				par->ceiling_color[i++] = ft_atoi(tmp->data);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&head);
}
