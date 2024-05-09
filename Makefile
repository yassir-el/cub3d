NAME = cub3d
NAME_BONUS = cub3d_bonus
CC = cc
SRCS = Mandatory/main.c Mandatory/parsing/ft_atoi.c Mandatory/parsing/ft_split.c Mandatory/parsing/ft_split_identifier.c Mandatory/parsing/get_next_line.c Mandatory/parsing/get_next_line_utils.c Mandatory/parsing/parse.c Mandatory/parsing/parse_info.c Mandatory/parsing/parse_info_2.c Mandatory/parsing/parse_map.c Mandatory/parsing/vec.c Mandatory/srcs/dda.c Mandatory/srcs/ft_keys.c Mandatory/srcs/ft_memset.c Mandatory/srcs/ft_textures.c Mandatory/srcs/ft_utils.c Mandatory/srcs/ft_utils_2.c Mandatory/srcs/ft_utils_3.c Mandatory/srcs/horz_vert.c Mandatory/srcs/main_raycasting.c Mandatory/srcs/move_draw.c Mandatory/srcs/render_walls.c

SRCS_BONUS = bonus/main_bonus.c  bonus/parsing/ft_atoi_bonus.c bonus/parsing/ft_split_bonus.c bonus/parsing/ft_split_identifier_bonus.c bonus/parsing/get_next_line_bonus.c bonus/parsing/get_next_line_utils_bonus.c bonus/parsing/parse_bonus.c bonus/parsing/parse_info_2_bonus.c bonus/parsing/parse_info_bonus.c bonus/parsing/parse_map_bonus.c bonus/parsing/vec_bonus.c bonus/srcs/dda_bonus.c bonus/srcs/ft_keys_bonus.c bonus/srcs/ft_memset_bonus.c bonus/srcs/ft_textures_bonus.c bonus/srcs/ft_utils_2_bonus.c bonus/srcs/ft_utils_3_bonus.c bonus/srcs/ft_utils_bonus.c bonus/srcs/horz_vert_bonus.c bonus/srcs/main_ray_bonus.c bonus/srcs/minimap_bonus.c bonus/srcs/move_draw_bonus.c bonus/srcs/render_walls_bonus.c

CFLAGS = -Wall -Wextra -Werror

OBJS=$(SRCS:.c=.o)

OBJS_BONUS=$(SRCS_BONUS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)

bonus:$(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS_BONUS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

ac: 
	make clean 
	make all 
	make clean

re: fclean all