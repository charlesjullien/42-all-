/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:17:30 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:13:23 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_exit(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	free_stuffs(char **cmd, t_cmd *lex)
{
	if (cmd)
		free_exit(cmd);
	if (lex)
		free_lex(lex);
	free_hist();
	free_env();
	exit(g_global.last_ret);
}

char	**execute_exit_more(char **cmd, t_cmd *lex)
{
	cmd[1] = ft_strjoin("exit: ", cmd[1]);
	ft_error(cmd[1], " : numeric argument required\n", 1, 2);
	g_global.last_ret = ft_atoi(cmd[1]);
	free_stuffs(cmd, lex);
	return (cmd);
}

void	execute_exit(char **cmd, int fd, t_cmd *lex)
{
	int	i;

	i = 0;
	g_global.last_ret = 0;
	ft_putstr_fd("exit\n", fd);
	if (cmd[1])
	{
		while (ft_isdigit(cmd[1][i]))
			i++;
		if (i != ft_strlen(cmd[1]))
			execute_exit_more(cmd, lex);
		if (i != ft_strlen(cmd[1]))
			return ;
		else if (cmd[2])
		{
			ft_error(NULL, "too many arguments\n", 1, 1);
			free_exit(cmd);
			return ;
		}
		else
			g_global.last_ret = ft_atoi(cmd[1]);
		free_stuffs(cmd, lex);
	}
}
