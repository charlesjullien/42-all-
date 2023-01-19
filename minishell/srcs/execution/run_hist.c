/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_hist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:18:10 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:19:11 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_hist(void)
{
	int	i;

	i = 0;
	while (g_global.hist[i] != NULL)
	{
		free(g_global.hist[i]);
		i++;
	}
	free(g_global.hist);
}

void	execute_hist(int fd)
{
	int		i;
	char	*str;

	i = 0;
	if (!g_global.hist)
		return ;
	while (g_global.hist[i] != NULL)
	{
		write(fd, "	", 2);
		str = ft_itoa(i + 1);
		write(fd, str, ft_strlen(str));
		write(fd, " ", 1);
		write(fd, g_global.hist[i], ft_strlen(g_global.hist[i]));
		write(fd, "\n", 1);
		i++;
		free(str);
	}
	g_global.last_ret = 0;
}
