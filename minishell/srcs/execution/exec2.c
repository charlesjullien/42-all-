/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:44:58 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 16:47:32 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**get_path(void)
{
	int	i;

	i = 0;
	if (g_global.env == NULL)
		return (NULL);
	while (g_global.env[i])
	{
		if (ft_strnstr(g_global.env[i], "PATH=", 5))
			return (ft_split(g_global.env[i], ':'));
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *arg)
{
	char	*path;
	char	**all_path;
	char	*tmp;
	int		i;

	if (arg && access(arg, X_OK) != -1)
		return (ft_strdup(arg));
	all_path = get_path();
	if (all_path == NULL)
		return (NULL);
	i = 0;
	while (all_path[i] != NULL)
	{
		tmp = ft_strjoin(all_path[i], "/");
		path = ft_strjoin(tmp, arg);
		if (access(path, X_OK) != -1)
			free_strs(all_path, tmp);
		if (access(path, X_OK) != -1)
			return (path);
		free(tmp);
		free(path);
		i++;
	}
	free_strs(all_path, NULL);
	return (NULL);
}
