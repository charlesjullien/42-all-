/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pip_redir2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 23:00:06 by mabuchar          #+#    #+#             */
/*   Updated: 2022/01/30 23:00:08 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pip_check_for_eof(const char *fin, char *rl)
{
	int	i;
	int	len_rl;
	int	len_fin;

	i = 0;
	len_rl = ft_strlen(rl);
	len_fin = ft_strlen(fin);
	while (rl && fin && rl[i] == fin[i] && i < len_fin)
	{
		i++;
	}
	if (i == len_fin && i == len_rl)
		return (1);
	return (0);
}

void	pip_inf_inf(const char *stop)
{
	char		*rl;
	const char	*fin;
	char		*res;

	fin = ft_strdup(stop);
	rl = readline ("> ");
	res = ft_strdup(rl);
	while (!check_for_eof(fin, rl) && rl != NULL)
	{
		free(rl);
		rl = readline ("> ");
		res = ft_strjoin(res, "\n");
		res = ft_strjoin(res, rl);
	}
	res = ft_strjoin(res, "\n");
	free(rl);
}

void	pip_inf(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	dup2(fd, STDIN_FILENO);
}

void	pip_sup_sup(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_APPEND);
	if (fd == -1)
		fd = open(file, O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
}

void	pip_sup(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY);
	if (fd == -1)
		fd = open(file, O_WRONLY | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
}
