#include "../cub3d.h"

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
