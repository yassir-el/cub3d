#include "../cub3d_bonus.h"

void	check_vert_move_with_door(t_cub3d *cub, float next_x, \
					float next_y, float current_x);
void	check_horz_move_wall(t_cub3d *cub, float next_x, \
							float next_y, float current_x);
void	check_vert_move_wall(t_cub3d *cub, float next_x, \
								float next_y, float current_x);
void	check_horz_move_with_door(t_cub3d *cub, float next_x, \
										float next_y, float current_x);

void	move_player(t_cub3d *cub)
{
	float	next_x;
	float	current_x;
	float	next_y;

	next_x = 0;
	current_x = 0;
	next_y = 0;
	cub->data.py.angle += 2 * PI / 180 * cub->data.py.rotation_mouse;
	if (cub->data.py.rotation != 0)
		cub->data.py.angle += cub->data.py.rotation * TURN_SPEED;
	if (cub->flag_unlock == 0)
	{
		if (cub->data.py.move_horz != 0)
			check_horz_move_wall(cub, next_x, next_y, current_x);
		if (cub->data.py.move_vert != 0)
			check_vert_move_wall(cub, next_x, next_y, current_x);
	}
	else
	{
		if (cub->data.py.move_horz != 0)
			check_horz_move_with_door(cub, next_x, next_y, current_x);
		if (cub->data.py.move_vert != 0)
			check_vert_move_with_door(cub, next_x, next_x, current_x);
	}
}

void	check_horz_move_wall(t_cub3d *cub, float next_x, \
							float next_y, float current_x)
{
	float	current_y;

	next_x = cub->data.py.pos_x + cos(cub->data.py.angle) * \
							cub->data.py.move_horz * WALK_SPEED;
	current_x = cub->data.py.pos_x;
	current_y = cub->data.py.pos_y;
	next_y = cub->data.py.pos_y + sin(cub->data.py.angle) * \
								cub->data.py.move_horz * WALK_SPEED;
	if (!(map_in(current_y, next_x, cub) != '1' && \
map_in(next_y, current_x, cub) != '1' && map_in(next_y, next_x, cub) == '1'))
	{
		if (map_in(current_y, next_x, cub) != '1')
			cub->data.py.pos_x = next_x;
		if (map_in(next_y, current_x, cub) != '1')
			cub->data.py.pos_y = next_y;
	}
}

void	check_vert_move_wall(t_cub3d *cub, float next_x, \
								float next_y, float current_x)
{
	float	current_y;

	next_x = cub->data.py.pos_x + cos(cub->data.py.angle + \
								90 * cub->data.py.move_vert) * WALK_SPEED;
	current_x = cub->data.py.pos_x;
	current_y = cub->data.py.pos_y;
	next_y = cub->data.py.pos_y + sin(cub->data.py.angle + \
								90 * cub->data.py.move_vert) * WALK_SPEED;
	if (!(map_in(current_y, next_x, cub) != '1' && \
map_in(next_y, current_x, cub) != '1' && map_in(next_y, next_x, cub) == '1'))
	{
		if (map_in(current_y, next_x, cub) != '1')
			cub->data.py.pos_x = next_x;
		if (map_in(next_y, current_x, cub) != '1')
			cub->data.py.pos_y = next_y;
	}
}

void	check_horz_move_with_door(t_cub3d *cub, float next_x, \
										float next_y, float current_x)
{
	float	current_y;

	next_x = cub->data.py.pos_x + cos(cub->data.py.angle) * \
									cub->data.py.move_horz * WALK_SPEED;
	current_x = cub->data.py.pos_x;
	current_y = cub->data.py.pos_y;
	next_y = cub->data.py.pos_y + sin(cub->data.py.angle) * \
										cub->data.py.move_horz * WALK_SPEED;
	if (!(map_in(current_y, next_x, cub) != '1' && \
		map_in(current_y, next_x, cub) != 'M' && \
		map_in(next_y, current_x, cub) != '1' && \
		map_in(next_y, current_x, cub) != 'M' && \
		(map_in(next_y, next_x, cub) == '1' || \
		map_in(next_y, next_x, cub) == 'M')))
	{
		if (map_in(current_y, next_x, cub) != '1' && \
				map_in(current_y, next_x, cub) != 'M')
			cub->data.py.pos_x = next_x;
		if (map_in(next_y, current_x, cub) != '1' && \
				map_in(next_y, current_x, cub) != 'M')
			cub->data.py.pos_y = next_y;
	}
}

void	check_vert_move_with_door(t_cub3d *cub, float next_x, \
										float next_y, float current_x)
{
	float	current_y;

	next_x = cub->data.py.pos_x + cos(cub->data.py.angle + 90 * \
									cub->data.py.move_vert) * WALK_SPEED;
	current_x = cub->data.py.pos_x;
	current_y = cub->data.py.pos_y;
	next_y = cub->data.py.pos_y + sin(cub->data.py.angle + 90 * \
									cub->data.py.move_vert) * WALK_SPEED;
	if (!(map_in(current_y, next_x, cub) != '1' && \
		map_in(current_y, next_x, cub) != 'M' && \
		map_in(next_y, current_x, cub) != '1' && \
		map_in(next_y, current_x, cub) != 'M' && \
		(map_in(next_y, next_x, cub) == '1' || \
		map_in(next_y, next_x, cub) == 'M' )))
	{
		if (map_in(current_y, next_x, cub) != '1' \
				&& map_in(current_y, next_x, cub) != 'M')
			cub->data.py.pos_x = next_x;
		if (map_in(next_y, current_x, cub) != '1' && \
			map_in(next_y, current_x, cub) != 'M')
			cub->data.py.pos_y = next_y;
	}
}
