/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mult_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:29:26 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:30:40 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execution(t_pip pip, t_cmd *lex)
{
	pip_redir(lex, &pip.fd, pip.index_pipe, 0);
	run_cmd_pip(pip, lex);
}

void	child(t_pip pip, int fd[2], int *fdd)
{
	if (*fdd != -1)
	{
		close(fd[0]);
		close(0);
		dup2(*fdd, 0);
		close(*fdd);
	}
	else
	{
		close(fd[0]);
	}
	if (pip.next)
	{
		close(1);
		dup2(fd[1], 1);
		close(fd[1]);
	}
}

int	run_mult_pipe(t_pip pip, t_cmd *lex, int fdd, int fd[2])
{
	fd[0] = -1;
	fd[1] = -1;
	if (pipe(fd))
		return (-1);
	if (parse_builtin(lex, pip.index_pipe) != 0)
		return (builtins(pip, lex, fd));
	g_global.pid = fork();
	if (g_global.pid < 0)
	{
		close_f(fd[0], fd[1]);
		close(fdd);
		return (-1);
	}
	else if (!g_global.pid)
	{
		child(pip, fd, &fdd);
		execution(pip, lex);
	}
	waitpid(g_global.pid, NULL, 0);
	return_child();
	close_f(fdd, fd[1]);
	return (fd[0]);
}

void	second_pipe(t_pip pip, t_cmd *lex)
{
	int	fd[2];

	pip.fdd = run_mult_pipe(pip, lex, pip.fdd, fd);
	while (pip.next == 1)
	{
		pip.index_pipe = look_for_pipe(pip.tab_ind,
				lex[0].x, pip.index_pipe) + 1;
		pip.next = more_pipe(pip.tab_ind, lex[0].x, pip.index_pipe);
		pip.fdd = run_mult_pipe(pip, lex, pip.fdd, fd);
		if (pip.fdd == -1)
			return ;
	}
	close(pip.fdd);
}

void	parse_mult_pipe(t_cmd *lex, int *tab_ind, int *fd2)
{
	t_pip	pip;

	pip.tab_ind = tab_ind;
	pip.fdd = -1;
	pip.fd = *fd2;
	pip.index_pipe = 0;
	pip.next = 1;
	second_pipe(pip, lex);
}
