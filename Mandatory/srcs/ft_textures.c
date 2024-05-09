#include "../cub3d.h"

void	ft_init_textures_2(t_cub3d *cub)
{
	cub->data.west.addr = mlx_get_data_addr(cub->data.west.img, \
		&cub->data.west.bits_per_pixel, &cub->data.west.size_line, \
						&cub->data.west.endian);
}

void	ft_init_textures(t_cub3d *cub)
{
	cub->data.east.img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
		cub->par.east_path, &cub->data.east.width, &cub->data.east.height);
	if (cub->data.east.img == NULL)
		ft_error_("Error\nError In XPM to IMG file East\n");
	cub->data.east.addr = mlx_get_data_addr(cub->data.east.img, \
		&cub->data.east.bits_per_pixel, &cub->data.east.size_line, \
		&cub->data.east.endian);
	cub->data.north.img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
		cub->par.north_path, &cub->data.north.width, &cub->data.north.height);
	if (cub->data.north.img == NULL)
		ft_error_("Error\nError In XPM to IMG file North\n");
	cub->data.north.addr = mlx_get_data_addr(cub->data.north.img, \
		&cub->data.north.bits_per_pixel, &cub->data.north.size_line, \
			&cub->data.north.endian);
	cub->data.south.img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
		cub->par.south_path, &cub->data.south.width, &cub->data.south.height);
	cub->data.west.img = mlx_xpm_file_to_image(cub->data.mlx_ptr, \
		cub->par.west_path, &cub->data.west.width, &cub->data.west.height);
	if (cub->data.south.img == NULL || cub->data.west.img == NULL)
		ft_error_("Error\nError In XPM to IMG file South or West\n");
	cub->data.south.addr = mlx_get_data_addr(cub->data.south.img, \
		&cub->data.south.bits_per_pixel, &cub->data.south.size_line, \
			&cub->data.south.endian);
	ft_init_textures_2(cub);
}
