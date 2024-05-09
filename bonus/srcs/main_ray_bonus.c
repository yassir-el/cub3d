#include "../cub3d_bonus.h"

void	init_win(t_data	*data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_error_("Error\nmlx_init Error\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
									WIN_WID, WIN_HEI, "Cub3d");
	if (data->win_ptr == NULL)
		ft_error_("Error\nmlx_new_window Error\n");
	data->s_img.img = mlx_new_image(data->mlx_ptr, WIN_WID, WIN_HEI);
	if (data->s_img.img == NULL)
		ft_error_("Error\nmlx_new_image Error\n");
	data->s_img.addr = mlx_get_data_addr(data->s_img.img, \
			&data->s_img.bits_per_pixel, &data->s_img.line_length, \
												&data->s_img.endian);
}

void	ft_init_var(t_cub3d *cub3d)
{
	if (cub3d->par.p_pos == 'N')
		cub3d->data.py.angle = 0;
	if (cub3d->par.p_pos == 'E')
		cub3d->data.py.angle = 90 * (PI / 180);
	if (cub3d->par.p_pos == 'S')
		cub3d->data.py.angle = 180 * (PI / 180);
	if (cub3d->par.p_pos == 'W')
		cub3d->data.py.angle = 270 * (PI / 180);
	cub3d->par.size_map = 0;
	while (cub3d->par.map[cub3d->par.size_map])
		cub3d->par.size_map++;
	cub3d->par.size_col = ft_strlen(cub3d->par.map[0]);
	cub3d->flag_unlock = 1;
	cub3d->data.py.pos_x = (cub3d->par.p_pos_x) * SQ_SIZE + SQ_SIZE / 2;
	cub3d->data.py.pos_y = (cub3d->par.p_pos_y) * SQ_SIZE + SQ_SIZE / 2;
	cub3d->par.map[cub3d->par.p_pos_y][cub3d->par.p_pos_x] = '0';
}

int	ft_2(t_cub3d *cub)
{
	mlx_clear_window(cub->data.mlx_ptr, cub->data.win_ptr);
	move_player(cub);
	call_rays(cub);
	render_mini_map(cub);
	mlx_put_image_to_window(cub->data.mlx_ptr, cub->data.win_ptr, \
									cub->data.s_img.img, 0, 0);
	return (0);
}

void	ft_check_textures(t_cub3d *cub)
{
	int	fd;

	fd = open(cub->par.east_path, O_RDONLY);
	if (fd < 0)
		ft_print_err(NULL, 1);
	close(fd);
	fd = open(cub->par.south_path, O_RDONLY);
	if (fd < 0)
		ft_print_err(NULL, 1);
	close(fd);
	fd = open(cub->par.north_path, O_RDONLY);
	if (fd < 0)
		ft_print_err(NULL, 1);
	close(fd);
	fd = open(cub->par.west_path, O_RDONLY);
	if (fd < 0)
		ft_print_err(NULL, 1);
	close(fd);
}

void	ft_main(t_cub3d *cub3d)
{
	ft_check_textures(cub3d);
	init_win(&cub3d->data);
	ft_init_textures(cub3d);
	ft_init_var(cub3d);
	alloc_map(cub3d);
	mlx_hook(cub3d->data.win_ptr, 17, 0, ft_close, &cub3d->data);
	mlx_hook(cub3d->data.win_ptr, 2, 0, ft_key_1, cub3d);
	mlx_hook(cub3d->data.win_ptr, 3, 0, ft_key_2, &cub3d->data);
	mlx_hook(cub3d->data.win_ptr, 4, 0, ft_mouse_1, &cub3d->data);
	mlx_hook(cub3d->data.win_ptr, 5, 0, ft_mouse_2, &cub3d->data);
	mlx_loop_hook(cub3d->data.mlx_ptr, ft_2, cub3d);
}
