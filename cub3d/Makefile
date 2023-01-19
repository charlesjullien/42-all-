.PHONY: all clean fclean re

NAME	=	cub3D
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
INC		=	includes
OBJ		=	objs
SRC		=	srcs
LIBFT	=	libft
LIBMLX	=	libmlx
INCS	=	$(addprefix $(INC)/, cub3d.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS	=	check_map.c \
				cub3d_utils.c \
				parse_dot_cub.c \
				parse_dot_cub_2.c \
				draw.c \
				hook.c \
				load_texture.c \
				start_game.c \
				mini_map.c \
				mlx_utils.c \
				move_pos_d_a.c \
				move_pos.c \
				ray_hor.c \
				ray_ver.c \
				raycasting.c

all: init $(NAME)

init:
	mkdir -p $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMLX)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) srcs/cub3d.c $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(OBJ)/%.o: $(SRC)/%.c $(INCS)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
