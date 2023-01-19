/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:17:43 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:25:57 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_var_from_env(int index)
{
	int	len;

	len = 0;
	while (g_global.env[len])
		len++;
	while (index + 1 < len)
	{
		g_global.env[index] = ft_strdup(g_global.env[index + 1]);
		index++;
	}
	g_global.env[index] = NULL;
	free(g_global.env[index]);
}

int	get_var_index(char *name)
{
	int	i;
	int	j;

	i = 0;
	while (g_global.env[i])
	{
		j = 0;
		while (g_global.env[i][j] == name[j])
			j++;
		if (j == ft_strlen(name) && g_global.env[i][j] == '=')
			return (i);
		i++;
	}
	return (-1);
}

void	execute_unset(char *name)
{
	int	index;

	g_global.last_ret = 0;
	index = get_var_index(name);
	if (index == -1)
		ft_error(name, ": not a valid identifier\n", 2, 1);
	if (index > -1)
		remove_var_from_env(index);
}
