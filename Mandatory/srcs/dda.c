#include "../cub3d.h"

void	ft_help(t_help *help, t_cub3d *cub, float rayAngle)
{
	help->dst_1 = get_distance(cub->data.py.pos_x, \
		cub->data.py.pos_y, help->next_x_1, help->next_y_1);
	help->dst_2 = get_distance(cub->data.py.pos_x, \
		cub->data.py.pos_y, help->next_x_2, help->next_y_2);
	if (help->dst_1 > help->dst_2)
	{
		cub->data.ray.wall_hit_x = help->next_x_2;
		cub->data.ray.wall_hit_y = help->next_y_2;
		cub->data.ray.distance = help->dst_2;
	}
	else
	{
		cub->data.ray.wall_hit_x = help->next_x_1 ;
		cub->data.ray.wall_hit_y = help->next_y_1 ;
		cub->data.ray.distance = help->dst_1;
	}
	cub->data.ray.distance = cub->data.ray.distance * \
						cos(rayAngle - cub->data.py.angle);
	cub->data.ray.wall_height = (((WIN_HEI) / \
						cub->data.ray.distance) * SQ_SIZE);
	help->start = (WIN_HEI / 2) - (cub->data.ray.wall_height / 2);
	help->end = (WIN_HEI / 2) + (cub->data.ray.wall_height / 2);
}

void	cast_rays(float rayAngle, t_cub3d *cub, int id)
{
	t_help	help;

	horizontal(rayAngle, cub, &help.next_x_1, &help.next_y_1);
	vertical(rayAngle, cub, &help.next_x_2, &help.next_y_2);
	ft_help(&help, cub, rayAngle);
	if (help.start < 0)
		help.start = 0;
	if (help.end >= WIN_HEI)
		help.end = WIN_HEI - 1;
	render_wall(id, help.start, help.end, cub);
}

void	call_rays(t_cub3d	*cub)
{
	float	ray_angle;
	int		i;

	i = 0;
	ray_angle = cub->data.py.angle - (FOV_A / 2);
	while (i < WIN_WID)
	{
		cast_rays(ray_angle, cub, i);
		ray_angle += (FOV_A / WIN_WID);
		i++;
	}
}
