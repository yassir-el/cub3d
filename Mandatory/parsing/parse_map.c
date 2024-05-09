#include "parse.h"

void	ft_map(t_list *head, char *prev)
{
	int	f;
	int	p_count;

	p_count = 0;
	f = 0;
	if (!head)
		ft_print_err("map error\n", 0);
	while (head)
	{
		check_line(head);
		check_line_2(head, prev, &f, &p_count);
		prev = head->data;
		head = head->next;
	}
	if (!p_count)
		ft_print_err("no player position\n", 0);
}

void	check_line(t_list *head)
{
	char	*s;

	s = head->data;
	if (!ft_strcmp(s, "\n"))
		ft_print_err("newline in map\n", 0);
	if (!head->next)
	{
		while (*s && (*s == '1' || *s == ' ' || *s == '\n'))
			s++;
		if (*s)
			ft_print_err("the map should be end with wall\n", 0);
	}
}

void	check_line_2(t_list *head, char *prev, int *f, int *p_count)
{
	int	i;

	i = -1;
	while (head->data[++i])
	{
		if (head->data[i] == ' ' || head->data[i] == '\n')
			*f = 0;
		else if (head->data[i] == '1')
			*f = 1;
		else if (head->data[i] == '0')
			ft_check_line_3(head, prev, f, i);
		else if (ft_find("NSWE", head->data[i]))
		{
			ft_check_line_3(head, prev, f, i);
			(*p_count)++;
			if (*p_count != 1)
				ft_print_err("many_players\n", 0);
		}
		else
			ft_print_err("not_valid_character\n", 0);
	}
	i -= head->data[i - 1] == '\n';
	if (i > 0 && head->data[i - 1] != '1' && head->data[i - 1] != ' ')
		ft_print_err("should have wall\n", 0);
}

void	ft_check_line_3(t_list *head, char *prev, int *f, int i)
{
	int	len_next;

	if ((!*f || !head->next))
		ft_print_err("wrong place of '0' or P\n", 0);
	len_next = ft_strlen(head->next->data);
	len_next -= head->next->data[len_next - 1] == '\n';
	check_mp(head, prev, len_next, i);
}

void	check_mp(t_list *head, char *prev, int len_next, int j)
{
	char	*s;
	int		len_prev;

	len_prev = ft_strlen(prev);
	s = head->data;
	len_prev--;
	if (j >= len_prev || j >= len_next)
		ft_print_err("wrong char surrounding 0 or P up and down\n", 0);
	if (prev[j] == ' ' || head->next->data[j] == ' '
		|| head->data[j + 1] == ' ')
		ft_print_err("wrong char surrounding 0 or P\n", 0);
}
