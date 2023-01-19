/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mult_pipe_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:19:39 by mabuchar          #+#    #+#             */
/*   Updated: 2022/01/30 11:19:42 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	many_pipe(int *tab_ind, int x)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < x)
	{
		if (tab_ind[i] == 8)
			index++;
		i++;
	}
	return (index);
}

int	more_pipe(int *tab_ind, int x, int start)
{
	int		i;

	if (start >= x)
		return (0);
	i = start;
	while (i < x && tab_ind[i] != 8)
		i++;
	if (i == x)
		return (0);
	return (1);
}

void	close_f(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

int	builtins(t_pip pip, t_cmd *lex, int fd[2])
{
	if (pip.next == 1)
	{
		check_from_or_to(lex, &fd[1], pip.index_pipe, 0);
		parse_tab_ind2(lex, pip.tab_ind, &pip.index_pipe, &fd[1]);
		close_f(fd[1], pip.fdd);
	}
	else if (pip.next == 0)
	{
		close_f(fd[1], pip.fdd);
		check_from_or_to(lex, &pip.fd, pip.index_pipe, 0);
		parse_tab_ind2(lex, pip.tab_ind, &pip.index_pipe, &pip.fd);
		return (fd[0]);
	}
	return (fd[0]);
}

void	run_cmd_pip(t_pip pip, t_cmd *lex)
{
	pip.arg = get_arg(lex, lex[0].x, &pip.index_pipe);
	pip.path = ft_get_path(pip.arg[0]);
	if (pip.path)
		execve(pip.path, pip.arg, g_global.env);
	else
	{
		free_strs(pip.arg, NULL);
		ft_error(lex[pip.index_pipe].tab, ": command not found", pip.fd, 0);
	}
}
