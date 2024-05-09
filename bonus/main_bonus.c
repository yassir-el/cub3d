#include "cub3d_bonus.h"

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (ac != 2)
	{
		write(2, "Error\nthe program take only one argument\n", 41);
		return (1);
	}
	ft_parse(av[1], &cub3d.par);
	ft_memset(&cub3d.data, 0, sizeof(cub3d.data));
	ft_main(&cub3d);
	mlx_loop(cub3d.data.mlx_ptr);
	return (0);
}
