/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 15:35:48 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/28 15:35:49 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_for_eof(const char *fin, char *rl)
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

void	inf_inf(const char *stop)
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

void	inf(char *file, int *fd)
{
	*fd = open(file, O_RDONLY);
}

void	sup_sup(char *file, int *fd)
{
	*fd = open(file, O_WRONLY | O_APPEND);
	if (*fd == -1)
		*fd = open(file, O_WRONLY | O_CREAT, 0644);
}

void	sup(char *file, int *fd)
{
	*fd = open(file, O_WRONLY);
	if (*fd == -1)
		*fd = open(file, O_WRONLY | O_CREAT, 0644);
}
