/* ************************************************************************** */
/*	                                                                        */
/*	                                                    :::      ::::::::   */
/*   minishell.h	                                    :+:      :+:    :+:   */
/*	                                                +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>	                +#+  +:+       +#+        */
/*	                                            +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:00:17 by cjullien	      #+#    #+#             */
/*   Updated: 2022/01/19 16:17:52 by cjullien         ###   ########.fr       */
/*	                                                                        */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*============================================================================*/
/*	                         define libraries                               */
/*============================================================================*/

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <ctype.h>
# include <dirent.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <errno.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "get_next_line.h"
# include "../libft/libft.h"

/*============================================================================*/
/*	                        define structures                               */
/*============================================================================*/

typedef struct s_global
{
	char	**env;
	char	**hist;
	int		pid;
	int		last_ret;
}				t_global;

t_global	g_global;

//	struct pipes
typedef struct s_pip
{
	int		index_pipe;
	int		next;
	char	**arg;
	char	*path;
	int		fdd;
	int		fd;
	int		*tab_ind;
}				t_pip;

//	struct cmd lexing   "lex"
typedef struct s_cmd
{
	char	sep;
	char	*tab;
	int		next_space;
	int		x;
	int		k;
	int		**tab_ind;
	t_pip	*pipes;
}				t_cmd;

// struct executions + pipe
typedef struct s_pid
{
	int		fd[2];
	int		pid1;
	int		pid2;
}				t_pid;

typedef struct s_var
{
	int		i;
	int		j;
	int		t;
	char	*tmp;
	char	*name_var;
}				t_var;

typedef struct s_int
{
	int		j;
	int		v;
}				t_int;

// typedef struct s_redir
// {
// 	int					out1;
// 	int					out2;
// 	int					in;
// 	int					sstdout;
// 	int					sstderr;
// 	int					sstdin;
// 	int					end;
// 	int					i;
// 	char				*name;
// 	char				*value;
// }t_redir;

/*============================================================================*/
/*	                        prototypes reading                              */
/*============================================================================*/

int				reading(void);//j'ai ajoutele void
void			prompt(void);
void			add_to_history(char *str);
void			ft_exit(t_cmd *lex, char *str);

/*============================================================================*/
/*	                        prototypes lexing                               */
/*============================================================================*/

int				lexing(char *line, int i);
int				should_break(char *line, int i, t_cmd *lex);
int				useless_spaces(char *line, int *i);
t_cmd			*ft_realloc_lex(t_cmd *lex);
int				check_sep(char c, char n);
int				check_pr(char c, char n);
void			print_lex(t_cmd *lex, int x);
void			free_lex(t_cmd *lex);
t_cmd			*what_sep(t_cmd *lex, char *line, int *i);
t_cmd			*no_sep(t_cmd *lex, int x, char *line, int *i);
void			find_index_quotes(char *line, int *i);
t_cmd			*simple_quotes(t_cmd *lex, int x, char *line, int *i);
t_cmd			*double_quotes(t_cmd *lex, int x, char *line, int *i);
t_cmd			*lex_pipe(t_cmd *lex, int x, int *i);
t_cmd			*lex_red_in(t_cmd *lex, int x, int *i);
t_cmd			*lex_red_out(t_cmd *lex, int x, int *i);
t_cmd			*lex_red_double_in(t_cmd *lex, int x, int *i);
t_cmd			*lex_red_double_out(t_cmd *lex, int x, int *i);

/*============================================================================*/
/*	                        prototypes parsing                              */
/*============================================================================*/

int				parcing(t_cmd *lex);
int				parse_builtin(t_cmd *lex, int i);
int				parse_builtin2(t_cmd *lex, int i);
int				ft_strcmp(const char *s1, const char *s2, size_t n);
void			parse_echo(t_cmd *lex, const int x, int *i, int *fd);
char			*check_variable(char *str, int i);
int				look_for_pipe(int *tab_ind, int x, int start);
void			parse_tab_ind(t_cmd *lex, int *tab_ind, int *fd);
void			parse_tab_ind2(t_cmd *lex, int *tab_ind, int *i, int *fd);
void			parse_cd(t_cmd *lex, int x, int *i, int *fd);
void			parse_pipes(t_cmd *lex, int *tab_ind, int *i, int *fd);
void			parse_export(t_cmd *lex, char *name, int *i, int *fd);
void			parse_unset(t_cmd *lex, int x, int *i);
void			parse_exit(t_cmd *lex, int x, int *i, int *fd);
void			close_fd(t_pid *pid);
char			*check_variable2(char **str, t_var *v, int *length_str);
void			sup(char *file, int *fd);
void			sup_sup(char *file, int *fd);
void			inf(char *file, int *fd);
void			inf_inf(const char *stop);
int				check_for_eof(const char *fin, char *rl);
void			parse_mult_pipe(t_cmd *lex, int *tab_ind, int *fd2);
void			second_pipe(t_pip pip, t_cmd *lex);
int				run_mult_pipe(t_pip pip, t_cmd *lex, int fdd, int fd[2]);
void			child(t_pip pip, int fd[2], int *fdd);
void			execution(t_pip pip, t_cmd *lex);
int				many_pipe(int *tab_ind, int x);
int				more_pipe(int *tab_ind, int x, int start);
void			close_f(int fd1, int fd2);
int				builtins(t_pip pip, t_cmd *lex, int fd[2]);
void			run_cmd_pip(t_pip pip, t_cmd *lex);
void			pip_redir(t_cmd *lex, int *fd, int i, int j);
void			pip_redirection(char *file, int token, int *fd, char *stop);
int				pip_is_file(char *str, int token);
int				pip_permission_ok(int *fd, char *str);
int				pip_check_for_eof(const char *fin, char *rl);
void			pip_inf_inf(const char *stop);
void			pip_inf(char *file);
void			pip_sup_sup(char *file);
void			pip_sup(char *file);

/*============================================================================*/
/*	                       prototypes execution                             */
/*============================================================================*/

char			*get_var_value(char *str);
char			*get_pwd(void);
void			redefine_env(char *name, char *new_value, int i, int k);
int				count_c_in_str(char *str, char c);
void			free_strs(char **big, char	*small);
int				free_split(char **tab, unsigned int j);
void			free_stuffs(char **cmd, t_cmd *lex);
unsigned int	get_nbr_words(char const *s, char c);
int				splitter(char **tab, char const *s, char c, unsigned int n);
char			**ft_split(char const *s, char c);
int				ft_append(char *str);
int				ft_override(char *str);
void			check_mod_and_type(char *str);
int				redirection(char *file, int token, int *fd, char *eof);
int				check_from_or_to(t_cmd *lex, int *fd, int i, int j);
int				change_directory(char *dest, char *path);
int				check_if_reachable(char *dest, char *pwd_save, char *path);
int				check_path(char *path, int fd);
void			execute_cd(char *path, int fd);
char			*reset_newline(char *str, int i);
void			execute_echo(char *str, int fd);
void			execute_env(int fd);
void			free_env(void);
int				set_env(char *env, char *new_env);
char			**realloc_envs(size_t size);
size_t			get_envs_count(void);
//static int		modify(char *new_env, size_t len, ssize_t i);
void			add_var_in_env(char *name, char *value, int i);
void			print_env(int fd, char **exp);
char			**copy_env(char *unasigned, int size);
void			set_env_alpha(char *unasigned, int print, int fd);
void			execute_export(int fd, char *name, char *value);
void			execute_pwd(int fd);
void			remove_var_from_env(int index);
int				get_var_index(char *name);
void			execute_unset(char *name);
int				str_contains_others_than(char *source, char *searched);
int				str_contains(char *source, char *searched);
void			sort_alpha(int i, int j, char **exp, char *temp);
void			execute_hist(int fd);
void			free_hist(void);
void			free_strs(char **big, char	*small);
char			**get_path(void);
char			*ft_get_path(char *arg);
int				check_access(t_cmd *lex);
void			return_child(void);
char			**get_arg(t_cmd *lex, const int x, int *i);
int				exec_cmd(t_cmd *lex, int *fd, int *i);
int				run_cmd(char **arg, char *path, t_cmd *lex, int *fd);
void			run_cmd1(t_cmd *lex, int x, int *i, t_pid *pid);
void			cmd1(t_pid *pid, char **arg, char *path);
void			run_cmd2(t_cmd *lex, int x, int *i, t_pid *pid);
void			cmd2(t_pid *pid, char **arg, char *path);

/*============================================================================*/
/*	                       prototypes exit error                            */
/*============================================================================*/

void			ft_error(char *s2, char *s3, int fd, int rv);
void			ft_error2(char *str, int fd);
void			execute_exit(char **cmd, int fd, t_cmd *lex);
void			free_exit(char **cmd);

/*============================================================================*/
/*	                         prototypes signals                             */
/*============================================================================*/

void			signal_handler(int sig);

#endif
