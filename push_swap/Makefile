NAME	=	push_swap
CC		=	clang
FLAGS	=	-Wall -Werror -Wextra
SRCS	=	srcs/6_or_more_utils.c srcs/check_errors.c srcs/main.c srcs/op_utils.c srcs/opa.c srcs/opb.c srcs/parsing.c srcs/push_swap_utils.c srcs/sort_6_or_more_2.c srcs/sort_6_or_more.c srcs/sort_less_6.c
INCS	=	$(addprefix includes/, push_swap.h)
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): ${OBJS} $(INCS)
	$(CC) $(FLAGS) -I includes -o $(NAME) $(OBJS)

%.o: %.c $(INCS)
	$(CC) $(FLAGS) -I includes -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all
