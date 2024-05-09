#include "../cub3d_bonus.h"

int	ft_key_1(int keyCode, t_cub3d *cub)
{
	if (keyCode == 53)
		ft_close(&cub->data);
	else if (keyCode == 123)
		cub->data.py.rotation = -1;
	else if (keyCode == 13)
		cub->data.py.move_horz = 1;
	else if (keyCode == 124)
		cub->data.py.rotation = 1;
	else if (keyCode == 1)
		cub->data.py.move_horz = -1;
	else if (keyCode == 2)
		cub->data.py.move_vert = 1;
	else if (keyCode == 0)
		cub->data.py.move_vert = -1;
	else if (keyCode == 37)
	{
		if (cub->par.map[(int )(cub->data.py.pos_y / \
	SQ_SIZE)][(int )(cub->data.py.pos_x / SQ_SIZE)] != 'M')
		{
			cub->flag_unlock = !cub->flag_unlock;
			cub->g_i = 0;
		}
	}
	return (0);
}

int	ft_key_2(int keyCode, t_data *data)
{
	if (keyCode == 123)
		data->py.rotation = 0;
	else if (keyCode == 13)
		data->py.move_horz = 0;
	else if (keyCode == 124)
		data->py.rotation = 0;
	else if (keyCode == 1)
		data->py.move_horz = 0;
	else if (keyCode == 0)
		data->py.move_vert = 0;
	else if (keyCode == 2)
		data->py.move_vert = 0;
	return (0);
}

int	ft_mouse_1(int button, int x, int y, t_cub3d *cub)
{
	(void)button;
	if (x > WIN_WID / 2 && x < WIN_WID && y > 0 && y < WIN_HEI)
		cub->data.py.rotation_mouse = 1;
	else if (x > 0 && x < WIN_WID / 2 && y > 0 && y < WIN_HEI)
		cub->data.py.rotation_mouse = -1;
	return (0);
}

int	ft_mouse_2(int button, int x, int y, t_cub3d *cub)
{
	(void)button;
	if (x > WIN_WID / 2 && x < WIN_WID && y > 0 && y < WIN_HEI)
		cub->data.py.rotation_mouse = 0;
	else if (x > 0 && x < WIN_WID / 2 && y > 0 && y < WIN_HEI)
		cub->data.py.rotation_mouse = 0;
	return (0);
}
