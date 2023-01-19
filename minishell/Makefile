NAME		=	minishell

HEADER		=	./includes/

LIBFT		=	libft/libft.a

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER)

SRCS 	=	srcs/get_next_line/get_next_line.c \
			srcs/get_next_line/get_next_line_utils.c \
			srcs/lexing/lex_malloc_free.c \
			srcs/lexing/lex_quotes.c \
			srcs/lexing/lex_double_quotes.c \
			srcs/lexing/lex_redirections_pipe.c \
			srcs/lexing/lex_utils.c \
			srcs/lexing/lexing.c \
			srcs/main_reading/main.c \
			srcs/main_reading/reading.c \
			srcs/main_reading/signals.c \
			srcs/parsing/parse_cd.c \
			srcs/parsing/parse_echo.c \
			srcs/parsing/parse_echo2.c \
			srcs/parsing/parse_exit.c \
			srcs/parsing/parse_export.c \
			srcs/parsing/parse_mult_pipe.c \
			srcs/parsing/parse_mult_pipe_add.c \
			srcs/parsing/pip_redir.c \
			srcs/parsing/pip_redir2.c \
			srcs/parsing/parse_unset.c \
			srcs/parsing/parse_utils.c \
			srcs/parsing/parsing.c \
			srcs/parsing/redirections.c \
			srcs/parsing/redirections2.c \
			srcs/execution/env_utils.c \
			srcs/execution/free_memory.c \
			srcs/execution/find_chars_utils.c \
			srcs/execution/ft_split.c \
			srcs/execution/run_cd.c \
			srcs/execution/run_echo.c \
			srcs/execution/run_env.c \
			srcs/execution/run_env2.c \
			srcs/execution/run_hist.c \
			srcs/execution/run_exit.c \
			srcs/execution/run_export.c \
			srcs/execution/run_export_2.c \
			srcs/execution/run_pwd.c \
			srcs/execution/run_unset.c \
			srcs/execution/error.c \
			srcs/execution/exec.c \
			srcs/execution/exec2.c \

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIBFT) $(HEADER)
				$(CC) $(CFLAGS) -lreadline $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT)	:
				make -C ./libft

clean		:
				rm -rf $(OBJS)
				make clean -C ./libft

fclean		:	clean
				rm $(NAME)
				make fclean -C ./libft

re			:	fclean all
