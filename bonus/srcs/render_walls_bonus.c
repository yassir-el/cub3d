#include "../cub3d_bonus.h"

unsigned int	ft_get_color(t_text *tex, t_cub3d *cub, int j, int wall_height)
{
	int				offset_x;
	int				offset_y;
	unsigned int	color;
	char			*dst;

	offset_x = ((int )(cub->data.ray.wall_hit_x + cub->data.ray.wall_hit_y) \
					% SQ_SIZE) * tex->width / SQ_SIZE;
	offset_y = (j - ((WIN_HEI / 2) - (cub->data.ray.wall_height / 2))) * \
					((float)tex->height / wall_height);
	color = 0;
	if (offset_x < tex->width && offset_y < tex->height && offset_x >= 0 \
											&& offset_y >= 0)
	{
		dst = tex->addr + (offset_y * tex->size_line + offset_x \
										* (tex->bits_per_pixel / 8));
		color = *(unsigned int *)dst;
	}
	return (color);
}

unsigned int	make_choise_2(t_cub3d *cub, int start_y)
{
	unsigned int	color;

	if (is_has_wall_2(cub->data.ray.wall_hit_x + 1, \
		cub->data.ray.wall_hit_y, cub) && \
			!is_has_wall_2(cub->data.ray.wall_hit_x - 1, \
					cub->data.ray.wall_hit_y, cub))
		color = ft_get_color(&cub->data.north, cub, \
						start_y, cub->data.ray.wall_height);
	else if (!is_has_wall_2(cub->data.ray.wall_hit_x, \
		cub->data.ray.wall_hit_y + 1, cub) && \
				is_has_wall_2(cub->data.ray.wall_hit_x, \
					cub->data.ray.wall_hit_y - 1, cub))
		color = ft_get_color(&cub->data.west, cub, start_y, \
				cub->data.ray.wall_height);
	else if (!is_has_wall_2(cub->data.ray.wall_hit_x + 1, \
		cub->data.ray.wall_hit_y, cub) && \
			is_has_wall_2(cub->data.ray.wall_hit_x - 1, \
					cub->data.ray.wall_hit_y, cub))
		color = ft_get_color(&cub->data.south, cub, start_y, \
						cub->data.ray.wall_height);
	else
		color = ft_get_color(&cub->data.east, cub, start_y, \
						cub->data.ray.wall_height);
	return (color);
}

unsigned int	make_choise(t_cub3d *cub, int start_y)
{
	unsigned int	color;

	color = 0;
	if (map_in(cub->data.ray.wall_hit_y, cub->data.ray.wall_hit_x, cub) == 'M')
	{
		if (cub->flag_unlock)
			color = ft_get_color(&cub->data.door[0], cub, \
							start_y, cub->data.ray.wall_height);
		else
		{
			cub->g_l = cub->g_i / 3000;
			if (cub->g_l < 7)
				color = ft_get_color(&cub->data.door[cub->g_l], \
							cub, start_y, cub->data.ray.wall_height);
		}
	}
	else
		color = make_choise_2(cub, start_y);
	return (color);
}

void	render_wall(int id_x, int start_y, int end_y, t_cub3d *cub)
{
	unsigned int	color;
	int				i;

	color = 0;
	i = -1;
	while (++i < start_y)
		my_mlx_pixel_put(&cub->data, id_x, i, \
			rgb_to_int(cub->par.floor_color[0], \
				cub->par.floor_color[1], cub->par.floor_color[2]));
	while (start_y < end_y)
	{
		color = make_choise(cub, start_y);
		if (color == 4278190080)
			return ;
		my_mlx_pixel_put(&cub->data, id_x, start_y, color);
		start_y++;
	}
	end_y -= 1;
	while (++end_y < WIN_HEI)
		my_mlx_pixel_put(&cub->data, id_x, end_y, \
			rgb_to_int(cub->par.ceiling_color[0], \
				cub->par.ceiling_color[1], cub->par.ceiling_color[2]));
	if (cub->g_i < 6000 * 3)
		cub->g_i++;
}
