#include "../cub3d.h"

float	get_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_error_(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}
