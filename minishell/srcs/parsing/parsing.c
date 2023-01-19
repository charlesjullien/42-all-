/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:37:06 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/28 13:49:38 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	parse_builtin2(t_cmd *lex, int i)
{
	if (lex[i].sep == '|')
		return (8);
	if (ft_strcmp(lex[i].tab, "<", 2) == 0)
		return (9);
	if (ft_strcmp(lex[i].tab, ">", 2) == 0)
		return (10);
	if (ft_strcmp(lex[i].tab, "<<", 2) == 0)
		return (11);
	if (ft_strcmp(lex[i].tab, ">>", 2) == 0)
		return (12);
	return (0);
}

int	parse_builtin(t_cmd *lex, int i)
{
	if (ft_strcmp(lex[i].tab, "echo", 10) == 0
		|| ft_strcmp(lex[i].tab, "/bin/echo", 10) == 0)
		return (1);
	if (ft_strcmp(lex[i].tab, "cd", 10) == 0)
		return (2);
	if (ft_strcmp(lex[i].tab, "pwd", 10) == 0)
		return (3);
	if (ft_strcmp(lex[i].tab, "export", 10) == 0)
		return (4);
	if (ft_strcmp(lex[i].tab, "unset", 10) == 0)
		return (5);
	if (ft_strcmp(lex[i].tab, "env", 10) == 0)
		return (6);
	if (ft_strncmp(lex[i].tab, "exit", 10) == 0)
		return (7);
	if (ft_strncmp(lex[i].tab, "history", 10) == 0)
		return (13);
	if (parse_builtin2(lex, i))
		return (parse_builtin2(lex, i));
	return (0);
}

void	parse_tab_ind2(t_cmd *lex, int *tab_ind, int *i, int *fd)
{
	if (*i < lex[0].x && tab_ind[*i] == 1)
		parse_echo(lex, lex[0].x, i, fd);
	else if (*i < lex[0].x && tab_ind[*i] == 2)
		parse_cd(lex, lex[0].x, i, fd);
	else if (*i < lex[0].x && tab_ind[*i] == 3)
		execute_pwd(*fd);
	else if (*i < lex[0].x && tab_ind[*i] == 4)
		parse_export(lex, NULL, i, fd);
	else if (*i < lex[0].x && tab_ind[*i] == 5)
		parse_unset(lex, lex[0].x, i);
	else if (*i < lex[0].x && tab_ind[*i] == 6)
		execute_env(*fd);
	else if (*i < lex[0].x && tab_ind[*i] == 7)
		parse_exit(lex, lex[0].x, i, fd);
	else if (*i < lex[0].x && tab_ind[*i] == 13)
		execute_hist(*fd);
	else if (check_access(lex))
		exec_cmd(lex, &lex[0].x, i);
	else
		ft_error(lex->tab, ": command not found\n", *fd, 127);
}

void	parse_tab_ind(t_cmd *lex, int *tab_ind, int *fd)
{
	int		i;
	int		many_pip;

	i = 0;
	many_pip = many_pipe(tab_ind, lex[0].x);
	if (many_pip >= 1)
		parse_mult_pipe(lex, tab_ind, fd);
	else
	{
		if (!check_from_or_to(lex, fd, 0, 0))
		{
			while (parse_builtin2(lex, i) > 8)
				i += 2;
			parse_tab_ind2(lex, tab_ind, &i, fd);
		}
	}
}

int	parcing(t_cmd *lex)
{
	int		*tab_ind;
	int		i;
	int		fd;

	tab_ind = malloc(sizeof(int) * lex[0].x);
	if (tab_ind == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	fd = 1;
	i = -1;
	while (++i < lex[0].x)
		tab_ind[i] = parse_builtin(lex, i);
	lex[0].tab_ind = &tab_ind;
	parse_tab_ind(lex, tab_ind, &fd);
	if (tab_ind)
		free(tab_ind);
	return (0);
}
