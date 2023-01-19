/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:36:14 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:25:11 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_exit_more(char **cmd)
{
	cmd[1] = ft_strdup("0");
	cmd[2] = NULL;
}

void	parse_exit(t_cmd *lex, int x, int *i, int *fd)
{
	char	**cmd;
	int		index;

	*i = *i + 1;
	cmd = malloc(sizeof(char *) * (x - *i + 3));
	if (cmd == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	cmd[0] = ft_strdup("exit");
	if (*i >= x)
		parse_exit_more(cmd);
	if (*i < x)
	{
		index = 1;
		while (*i < x)
		{
			cmd[index] = ft_strdup(lex[*i].tab);
			index++;
			*i = *i + 1;
		}
		cmd[index] = NULL;
	}
	execute_exit(cmd, *fd, lex);
}
