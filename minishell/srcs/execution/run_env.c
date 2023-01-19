/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:06:30 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:07:42 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

ssize_t	find_env(char *env, ssize_t i)
{
	char	*sub;
	ssize_t	index;

	if (!env)
		return (-1);
	sub = NULL;
	while (g_global.env[i])
	{
		index = ft_get_char_by_index(g_global.env[i], '=');
		if (index == -1)
			index = ft_strlen(g_global.env[i]);
		sub = ft_substr(g_global.env[i], 0, index);
		if (sub)
		{
			if (ft_strequ(sub, env))
			{
				free(sub);
				return (i);
			}
			free(sub);
		}
		i++;
	}
	return (-1);
}

static int	modify(char *new_env, size_t len, ssize_t i)
{
	char	*tmp;
	char	*new;

	tmp = ft_substr(g_global.env[i], 0, (len + 1));
	if (tmp == NULL)
		return (0);
	new = ft_strjoin(tmp, new_env);
	if (new == NULL)
		return (0);
	free(g_global.env[i]);
	free(tmp);
	g_global.env[i] = new;
	return (1);
}

int	set_env(char *env, char *new_env)
{
	char	*tmp;
	ssize_t	i;
	size_t	len;

	if (!env || !new_env)
		return (0);
	len = ft_strlen(env);
	i = -1;
	i = find_env(env, 0);
	if (i != -1)
		return (modify(new_env, len, i));
	else
	{
		len = get_envs_count() + 1;
		g_global.env = realloc_envs(len);
		tmp = ft_strjoin(env, "=");
		g_global.env[len - 1] = ft_strjoin(tmp, new_env);
		free(tmp);
		return (1);
	}
	return (0);
}

void	free_env(void)
{
	int	i;

	i = 0;
	while (g_global.env[i] != NULL)
	{
		free(g_global.env[i]);
		i++;
	}
	free(g_global.env);
}

void	execute_env(int fd)
{
	int	i;

	i = 0;
	while (g_global.env[i])
	{
		write(fd, g_global.env[i], ft_strlen(g_global.env[i]));
		write(fd, "\n", 1);
		i++;
	}
	g_global.last_ret = 0;
}
