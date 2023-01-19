NAME		=	philo

HEADER		=	include/

CC			=	clang

CFLAGS		=	-Werror -Wall -Wextra -g

SRCS		=	srcs/main.c \
				srcs/libft_utils.c \
				srcs/parsing.c \
				srcs/threads.c \
				srcs/threads2.c \
				srcs/philo_utils.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) -lpthread -o $(NAME) $(OBJS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY	:	re clean fclean
