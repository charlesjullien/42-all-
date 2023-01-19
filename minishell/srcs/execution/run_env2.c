/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_env2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:08:39 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:09:02 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**realloc_envs(size_t size)
{
	char	**new;
	size_t	i;

	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (new == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	i = 0;
	while (g_global.env[i] && i < size)
	{
		new[i] = ft_strdup(g_global.env[i]);
		i++;
	}
	new[size] = 0;
	free_env();
	return (new);
}

size_t	get_envs_count(void)
{
	size_t	count;

	count = 0;
	while (g_global.env[count])
		count++;
	return (count);
}
