.PHONY: all clean fclean re

CC		=	gcc
NAME	=	pipex
FLAGS	=	-Wall -Wextra -Werror -g

INC		=	pipex.h
OBJ		=	objs
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	main.c \
			strs_utils.c \
			ft_split.c \
			pipex_utils.c

$(NAME): $(OBJ) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJ):
	@mkdir -p $(OBJ)

$(OBJ)/%.o: ./%.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
