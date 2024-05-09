#include "../cub3d.h"

unsigned int	rgb_to_int(int r, int g, int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

int	is_has_wall_2(float x, float y, t_cub3d *cub)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0 || x >= cub->par.size_col * SQ_SIZE \
							|| y >= cub->par.size_map * SQ_SIZE)
		return (1);
	map_x = (int )(x / SQ_SIZE);
	map_y = (int )(y / SQ_SIZE);
	if (map_x >= 0 && map_y >= 0 && map_x < cub->par.size_col \
										&& map_y < cub->par.size_map)
		return (cub->par.map[map_y][map_x] == '1');
	return (1);
}

char	map_in(float y, float x, t_cub3d *cub)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0 || x >= cub->par.size_col * SQ_SIZE \
							|| y >= cub->par.size_map * SQ_SIZE)
		return ('1');
	map_x = (int )(x / SQ_SIZE);
	map_y = (int )(y / SQ_SIZE);
	if (map_x >= 0 && map_y >= 0 && map_x < cub->par.size_col \
										&& map_y < cub->par.size_map)
		return (cub->par.map[map_y][map_x]);
	return ('1');
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WID || y >= WIN_HEI)
		return ;
	dst = data->s_img.addr + (y * data->s_img.line_length + x * \
									(data->s_img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit(0);
}
