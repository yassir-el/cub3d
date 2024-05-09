#ifndef CUB3D_H
# define CUB3D_H

# include "parsing/parse.h"
# include <mlx.h>
# include <math.h>
# include <string.h>

# define WIN_WID    1280
# define WIN_HEI   720
# define PI 3.141592653589793238
# define TURN_SPEED 0.06981317007
# define WALK_SPEED 10
# define SQ_SIZE 50
# define FOV_A 1.0471975512

typedef struct s_py
{
	float	angle;
	int		rotation;
	int		move_horz;
	int		move_vert;
	int		rotation_mouse;
	float	pos_x;
	float	pos_y;
}	t_py;

typedef struct s_ray
{
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	float	wall_height;
}	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_text
{
	int		width;
	int		height;

	void	*img;
	char	*addr;
	int		endian;
	int		bits_per_pixel;
	int		size_line;
}	t_text;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_py	py;
	t_img	s_img;
	t_ray	ray;
	t_text	north;
	t_text	south;
	t_text	east;
	t_text	west;
}	t_data;

typedef struct s_cub3d
{
	t_data	data;
	t_parse	par;
}	t_cub3d;

typedef struct s_help{
	float	next_x_1;
	float	next_y_1;
	float	dst_1;
	float	dst_2;
	float	next_x_2;
	float	next_y_2;
	float	start;
	float	end;
}	t_help;

typedef struct s_help_2{
	float	lmohadi;
	float	lmo9abil;
	double	delta_y;
	double	delta_x;
	int		is_right;
	int		is_down;
}	t_help_2;

void			move_player(t_cub3d *cub);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			call_rays(t_cub3d	*cub);
void			*ft_memset(void *b, int c, size_t len);
char			map_in(float y, float x, t_cub3d *cub);
int				is_has_wall_2(float x, float y, t_cub3d *cub);
unsigned int	rgb_to_int(int r, int g, int b);
int				ft_close(t_data *data);
int				ft_key_1(int keyCode, t_cub3d *cub);
int				ft_key_2(int keyCode, t_data *data);
void			ft_init_textures(t_cub3d *cub);
void			ft_error_(char *str);
char			*ft_itoa(int n);
char			*ft_strjoin(char *s1, char *s2);
int				has_wall(float x, float y, t_cub3d *cub);
float			get_distance(float x1, float y1, float x2, float y2);
void			init_win(t_data	*data);
void			ft_init_var(t_cub3d *cub3d);
int				ft_2(t_cub3d *cub);
void			ft_check_textures(t_cub3d *cub);
void			ft_main(t_cub3d *cub3d);
void			render_wall(int id_x, int start_y, int end_y, t_cub3d *cub);

void			horizontal(float rayAngle, t_cub3d *cub, float *nextX, \
																float *nextY);
void			horizontal__2(float rayAngle, t_cub3d *cub, float *nextX, \
																float *nextY);
void			vertical(float rayAngle, t_cub3d *cub, float *nextX, \
																float *nextY);
void			vertical__2(float rayAngle, t_cub3d *cub, float *nextX, \
																float *nextY);
#endif