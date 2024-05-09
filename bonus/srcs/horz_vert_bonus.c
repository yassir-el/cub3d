#include "../cub3d_bonus.h"

void	horizontal(float rayAngle, t_cub3d *cub, float *nextX, float *nextY)
{
	t_help_2	help;

	help.is_down = (sin(rayAngle) > 0);
	*nextY = (int )(cub->data.py.pos_y - (int )(cub->data.py.pos_y) % SQ_SIZE);
	if (help.is_down)
		*nextY += SQ_SIZE;
	help.lmohadi = ((*nextY - cub->data.py.pos_y));
	help.lmo9abil = help.lmohadi / tan(rayAngle);
	*nextX = cub->data.py.pos_x + help.lmo9abil;
	help.delta_x = SQ_SIZE / tan(rayAngle);
	help.delta_y = SQ_SIZE;
	if (!help.is_down)
		help.delta_y *= -1;
	if (!help.is_down)
		help.delta_x *= -1;
	if (!help.is_down)
		(*nextY)--;
	while (*nextY >= 0 && *nextY < cub->par.size_map * SQ_SIZE && \
						*nextX >= 0 && *nextX < cub->par.size_col * SQ_SIZE)
	{
		if (has_wall(*nextX, *nextY, cub))
			break ;
		*nextX += help.delta_x;
		*nextY += help.delta_y;
	}
}

void	horizontal__2(float rayAngle, t_cub3d *cub, float *nextX, float *nextY)
{
	t_help_2	help;

	*nextY = (int )(cub->data.py.pos_y - (int )(cub->data.py.pos_y) % SQ_SIZE);
	if (sin(rayAngle) > 0)
		*nextY += SQ_SIZE;
	help.lmo9abil = ((*nextY - cub->data.py.pos_y)) / tan(rayAngle);
	*nextX = cub->data.py.pos_x + help.lmo9abil;
	help.delta_x = SQ_SIZE / tan(rayAngle);
	help.delta_y = SQ_SIZE;
	if (sin(rayAngle) < 0)
		help.delta_y *= -1;
	if (sin(rayAngle) < 0)
		help.delta_x *= -1;
	if (sin(rayAngle) < 0)
		(*nextY)--;
	while (*nextY >= 0 && *nextY < cub->par.size_map * SQ_SIZE \
						&& *nextX >= 0 && *nextX < cub->par.size_col * SQ_SIZE)
	{
		if (has_wall(*nextX, *nextY, cub))
			break ;
		if (map_in(*nextY, *nextX, cub) == 'M')
			break ;
		*nextX += help.delta_x;
		*nextY += help.delta_y;
	}
}

void	vertical(float rayAngle, t_cub3d *cub, float *nextX, float *nextY)
{
	t_help_2	help;

	help.is_right = (cos(rayAngle) < 0);
	*nextX = (int )(cub->data.py.pos_x - (int )(cub->data.py.pos_x) % SQ_SIZE);
	if (help.is_right == 0)
		*nextX += SQ_SIZE;
	help.lmohadi = ((*nextX - cub->data.py.pos_x));
	help.lmo9abil = help.lmohadi * tan(rayAngle);
	*nextY = cub->data.py.pos_y + help.lmo9abil;
	help.delta_y = (SQ_SIZE * tan(rayAngle));
	help.delta_x = SQ_SIZE;
	if (help.is_right == 1)
		help.delta_y *= -1;
	if (help.is_right == 1)
		help.delta_x *= -1;
	if (help.is_right)
		(*nextX) -= 0.001;
	while (*nextY >= 0 && *nextY <= cub->par.size_map * SQ_SIZE \
					&& *nextX >= 0 && *nextX <= cub->par.size_col * SQ_SIZE)
	{
		if (has_wall(*nextX, *nextY, cub))
			break ;
		*nextX += help.delta_x;
		*nextY += help.delta_y;
	}
}

void	vertical__2(float rayAngle, t_cub3d *cub, float *nextX, float *nextY)
{
	t_help_2	help;

	*nextX = (int )(cub->data.py.pos_x - (int )(cub->data.py.pos_x) % SQ_SIZE);
	if (cos(rayAngle) > 0)
		*nextX += SQ_SIZE;
	help.lmo9abil = ((*nextX - cub->data.py.pos_x)) * tan(rayAngle);
	*nextY = cub->data.py.pos_y + help.lmo9abil;
	help.delta_y = (SQ_SIZE * tan(rayAngle));
	help.delta_x = SQ_SIZE;
	if (cos(rayAngle) < 0)
		help.delta_y *= -1;
	if (cos(rayAngle) < 0)
		help.delta_x *= -1;
	if (cos(rayAngle) < 0)
		(*nextX) -= 0.001;
	while (*nextY >= 0 && *nextY <= cub->par.size_map * SQ_SIZE && \
					*nextX >= 0 && *nextX <= cub->par.size_col * SQ_SIZE)
	{
		if (has_wall(*nextX, *nextY, cub))
			break ;
		if (map_in(*nextY, *nextX, cub) == 'M')
			break ;
		*nextX += help.delta_x;
		*nextY += help.delta_y;
	}
}
