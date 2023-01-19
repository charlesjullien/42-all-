/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:43:56 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 12:46:14 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process(int sig)
{
	if (!kill(g_global.pid, sig))
	{
		if (sig == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			g_global.last_ret = 131;
		}
		else if (sig == SIGINT)
		{
			ft_putstr_fd("\n", 1);
			g_global.last_ret = 130;
		}
	}
	else if (sig == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		g_global.last_ret = 1;
		prompt();
	}
}

void	signal_handler(int sig)
{
	if ((sig == SIGINT || sig == SIGQUIT)
		&& g_global.pid != 0)
		process(sig);
	else
	{
		if (sig == SIGINT)
		{
			ft_putstr_fd("\n", 1);
			g_global.last_ret = 1;
			prompt();
		}
		else if (sig == SIGQUIT)
			ft_putstr_fd("\b\b  \b\b", 1);
	}
}
