/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:59:58 by mabuchar          #+#    #+#             */
/*   Updated: 2022/01/30 23:00:00 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	look_for_pipe(int *tab_ind, int x, int start)
{
	int		i;

	if (start >= x)
		return (-1);
	i = start;
	while (i < x && tab_ind[i] != 8)
		i++;
	if (i == x)
		return (-1);
	return (i);
}

int	pip_permission_ok(int *fd, char *str)
{
	*fd = open(str, O_WRONLY);
	if (*fd == -1)
		return (0);
	return (1);
}

int	pip_is_file(char *str, int token)
{
	struct stat	buf;
	int			check;

	stat(str, &buf);
	check = open(str, O_WRONLY);
	if (check == -1 && (token == 1 || token == 2))
	{
		close(check);
		return (1);
	}
	close(check);
	if (!S_ISREG(buf.st_mode))
		return (0);
	return (1);
}

void	pip_redirection(char *file, int token, int *fd, char *stop)
{
	if (file && token != 4 && pip_is_file(file, token) == 0)
		ft_error(file, ": not a valid file\n", *fd, 0);
	if (token != 4 && pip_permission_ok(fd, file) == 0)
		ft_error(file, ": Permission denied\n", *fd, 0);
	if (token == 1)
		pip_sup(file);
	if (token == 2)
		pip_sup_sup(file);
	if (token == 3)
		pip_inf(file);
	if (token == 4)
		pip_inf_inf(stop);
}

void	pip_redir(t_cmd *lex, int *fd, int i, int j)
{
	while (i < lex->x)
	{
		if (lex[i].sep == '|')
			break ;
		if (lex[i].sep)
		{
			if (lex[i].tab[j] == '>' && lex[i].tab[j + 1]
				&& lex[i].tab[j + 1] == '>')
				if (lex[i + 1].tab)
					pip_redirection(lex[i + 1].tab, 2, fd, NULL);
			if (lex[i].tab[j] == '>' && lex[i].tab[j + 1] == '\0')
				pip_redirection(lex[i + 1].tab, 1, fd, NULL);
			if (lex[i].tab[j] == '<' && lex[i].tab[j + 1]
				&& lex[i].tab[j + 1] == '<')
				if (lex[i + 1].tab)
					pip_redirection(NULL, 4, fd, lex[i + 1].tab);
			if (lex[i].tab[j] == '<' && lex[i].tab[j + 1] == '\0')
				pip_redirection(NULL, 3, fd, NULL);
		}
		i++;
	}
}
