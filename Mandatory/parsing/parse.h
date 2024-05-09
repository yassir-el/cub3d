#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# include "get_next_line.h"
# include "vec.h"

typedef struct s_parse
{
	char	*north_path;
	char	*south_path;
	char	*east_path;
	char	*west_path;

	int		p_pos_x;
	int		p_pos_y;
	char	p_pos;

	int		floor_color[3];
	int		ceiling_color[3];

	char	**map;
	int		size_map;
	int		size_col;
}t_parse;

void	ft_print_err(char *s, int pr);
void	read_file(t_list **head, char *file);
void	ft_parse(char *s, t_parse *par_info);
void	copy_map_continue(t_list *head, t_parse *par_info, int max_len);

void	ft_map(t_list *head, char *prev);
void	check_line(t_list *head);
void	check_line_2(t_list *head, char *prev, int *f, int *p_count);
void	ft_check_line_3(t_list *head, char *prev, int *f, int i);
void	check_mp(t_list *head, char *prev, int len_next, int j);

void	parse_info(t_list **head, t_parse *par_info);
void	ft_identifier_parse(char *line, t_parse *par, char *bool_);
void	ft_identifier(char *s, char *bool_);
void	ft_way(char **data, t_parse *par);
void	ft_way_2(char **data, t_parse *par);

void	ft_way_2_0(char **data, t_list **head);
void	ft_check(t_list *head);
int		ft_find(char *s, char c);
int		ft_isdigit(char *s);

void	ft_copy_map(t_list *head, t_parse *par_info);
void	*ft_memset(void *b, int c, size_t len);
char	**ft_split_identifier(char *line);
int		ft_strcmp(char *a, char *b);
char	*ft_strdup(char *s1);

#endif
