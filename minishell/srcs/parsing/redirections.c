/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:36:15 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:40:10 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	permission_ok(int *fd, char *str)
{
	*fd = open(str, O_WRONLY);
	if (*fd == -1)
		return (0);
	return (1);
}

int	is_file(char *str, int token)
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

int	redirection(char *file, int token, int *fd, char *stop)
{
	if (file && token != 4 && is_file(file, token) == 0)
		ft_error(file, ": not a valid file\n", *fd, 0);
	if (token != 4 && permission_ok(fd, file) == 0)
		ft_error(file, ": Permission denied\n", *fd, 0);
	if (token == 1)
		sup(file, fd);
	if (token == 2)
		sup_sup(file, fd);
	if (token == 3)
		inf(file, fd);
	if (token == 4)
		inf_inf(stop);
	if (stop)
		return (1);
	return (0);
}

int	check_from_or_to(t_cmd *lex, int *fd, int i, int j)
{
	int	k;

	k = 0;
	while (i < lex->x)
	{
		if (lex[i].sep == '|')
			break ;
		if (lex[i].sep)
		{
			if (lex[i].tab[j] == '>' && lex[i].tab[j + 1]
				&& lex[i].tab[j + 1] == '>')
				if (lex[i + 1].tab)
					redirection(lex[i + 1].tab, 2, fd, NULL);
			if (lex[i].tab[j] == '>' && lex[i].tab[j + 1] == '\0')
				redirection(lex[i + 1].tab, 1, fd, NULL);
			if (lex[i].tab[j] == '<' && lex[i].tab[j + 1]
				&& lex[i].tab[j + 1] == '<')
				if (lex[i + 1].tab)
					k = redirection(NULL, 4, fd, lex[i + 1].tab);
			if (lex[i].tab[j] == '<' && lex[i].tab[j + 1] == '\0')
				redirection(NULL, 3, fd, NULL);
		}
		i++;
	}
	return (k);
}
