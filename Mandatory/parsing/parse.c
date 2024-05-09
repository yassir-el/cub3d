#include "parse.h"

void	read_file(t_list **head, char *file)
{
	int	l;

	l = ft_strlen(file) - 4;
	if (l < 0 || ft_strcmp(file + l, ".cub"))
		ft_print_err("the file must have .cub as extension\n", 0);
	l = open(file, O_RDONLY);
	if (l == -1)
		ft_print_err(NULL, 1);
	while ('_')
	{
		file = get_next_line(l);
		if (!file)
			break ;
		ft_push(head, ft_new(file));
	}
	close(l);
}

void	ft_parse(char *s, t_parse *par_info)
{
	t_list	*head;
	t_list	*temp;
	t_list	*map;
	int		i;

	ft_memset(par_info, 0, sizeof(t_parse));
	head = NULL;
	read_file(&head, s);
	temp = head;
	parse_info(&head, par_info);
	while (head && !ft_strcmp(head->data, "\n"))
		head = head->next;
	if (!head)
		ft_print_err("where is the map\n", 0);
	i = -1;
	map = head;
	while (head->data[++i])
	{
		if (head->data[i] != '1' && head->data[i] != ' '
			&& head->data[i] != '\n')
			ft_print_err("map must be surounded by walls\n", 0);
	}
	ft_map(head->next, head->data);
	ft_copy_map(map, par_info);
	ft_lstclear(&temp);
}

void	ft_copy_map(t_list *head, t_parse *par_info)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		max2;

	tmp = head;
	max = 0;
	max2 = 0;
	i = 0;
	while (tmp)
	{
		max = ft_strlen(tmp->data);
		max -= tmp->data[max - 1] == '\n';
		max2 = ((max >= max2) * max) + ((max2 > max) * max2);
		tmp = tmp->next;
		++i;
	}
	par_info->map = malloc(sizeof(char *) * (i + 1));
	copy_map_continue(head, par_info, max2);
}

void	copy_map_continue(t_list *head, t_parse *par_info, int max_len)
{
	int	i;
	int	j;

	j = 0;
	while (head)
	{
		par_info->map[j] = malloc(sizeof(char) * (max_len + 1));
		i = 0;
		while (head->data[i] && head->data[i] != '\n')
		{
			if (ft_find("NSWE", head->data[i]))
			{
				par_info->p_pos_x = i;
				par_info->p_pos_y = j;
				par_info->p_pos = head->data[i];
			}
			par_info->map[j][i] = head->data[i];
			++i;
		}
		while (i < max_len)
			par_info->map[j][i++] = ' ';
		par_info->map[j++][i] = '\0';
		head = head->next;
	}
	par_info->map[j] = NULL;
}
