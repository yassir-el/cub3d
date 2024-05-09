#include "../cub3d_bonus.h"
#include <unistd.h>

void	draw_rect(int x, int y, t_data *data)
{
	int	row;
	int	col;

	row = y;
	while (row < y + SIZE_PLAYER)
	{
		col = x;
		while (col < x + SIZE_PLAYER)
		{
			my_mlx_pixel_put(data, col, row, COLOR_MINI_MAP);
			col++;
		}
		row++;
	}
}

void	ft_alloc_map_2(t_cub3d *cub, int i, int j)
{
	unsigned int	color;
	int				l;
	int				k;
	char			*dst;

	l = -1;
	if (cub->par.map[i][j] == '1')
		color = 255;
	else if (cub->par.map[i][j] == '0')
		color = 255 * 255;
	while (++l < SQ_SIZE)
	{
		k = -1;
		while (++k < SQ_SIZE)
		{
			dst = cub->mini.add + ((l + i * SQ_SIZE) * \
	cub->mini.size_line + (k + j * SQ_SIZE) * (cub->mini.bits / 8));
			*(unsigned int *)dst = color;
		}
	}
}

void	alloc_map(t_cub3d *cub)
{
	int				i;
	int				j;

	cub->mini.img = mlx_new_image(cub->data.mlx_ptr, \
			cub->par.size_col * SQ_SIZE, cub->par.size_map * SQ_SIZE);
	cub->mini.add = mlx_get_data_addr(cub->mini.img, \
			&cub->mini.bits, &cub->mini.size_line, &cub->mini.endian);
	i = -1;
	while (++i < cub->par.size_map)
	{
		j = -1;
		while (++j < cub->par.size_col)
			ft_alloc_map_2(cub, i, j);
	}
}

void	ft_render_2(t_cub3d *cub, int i, int x, int y)
{
	unsigned int	color;
	char			*dst;
	int				j;

	j = -101;
	while (++j < 100)
	{
		color = 0;
		if (!(i + cub->data.py.pos_y < 0 || j + cub->data.py.pos_x < 0 \
			|| j + cub->data.py.pos_x >= cub->par.size_col * SQ_SIZE || \
				i + cub->data.py.pos_y >= cub->par.size_map * SQ_SIZE))
		{
			dst = cub->mini.add + ((int )(i + cub->data.py.pos_y) * \
				cub->mini.size_line + (int )(j + cub->data.py.pos_x) * \
													(cub->mini.bits / 8));
			color = *(unsigned int *)dst;
		}
		if (color != 0)
			my_mlx_pixel_put(&cub->data, x, y, color);
		y++;
	}
}

void	render_mini_map(t_cub3d *cub)
{
	int				x;
	int				y;
	int				i;

	i = -101;
	x = 0;
	while (++i < 100)
	{
		y = 0;
		ft_render_2(cub, i, x, y);
		x++;
	}
	draw_rect(95, 95, &cub->data);
}
