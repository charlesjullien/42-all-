/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:18:09 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:16:19 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_var_in_env(char *name, char *value, int i)
{
	char	**new;

	while (g_global.env[i])
		i++;
	new = malloc(sizeof(char *) * (i + 2));
	if (!new)
		ft_exit(NULL, "Warning : Malloc failed\n");
	i = 0;
	while (g_global.env[i])
	{
		new[i] = ft_strdup(g_global.env[i]);
		i++;
	}
	new[i] = ft_strjoin(name, "=");
	new[i] = ft_strjoin(new[i], value);
	i++;
	new[i] = 0;
	free(g_global.env);
	g_global.env = NULL;
	g_global.env = new;
}

void	print_env(int fd, char **exp)
{
	int	i;
	int	j;
	int	cote;

	i = 0;
	cote = 0;
	while (exp[i])
	{
		j = 0;
		write(fd, "declare -x ", 11);
		while (exp[i][j])
		{
			write(fd, &exp[i][j], 1);
			if (exp[i][j] == '=')
			{
				write(fd, "\"", 1);
				cote = 1;
			}
			j++;
		}
		if (cote)
			write(fd, "\"", 1);
		write(fd, "\n", 1);
		i++;
	}
}

char	**copy_env(char *unasigned, int size)
{
	int		i;
	char	**dup;

	size++;
	i = 0;
	while (g_global.env[i])
		i++;
	dup = malloc(sizeof(char *) * (i + 1));
	if (!dup)
		ft_exit(NULL, "Warning : Malloc failed\n");
	i = 0;
	while (g_global.env[i])
	{
		dup[i] = ft_strdup(g_global.env[i]);
		i++;
	}
	if (unasigned)
		dup[i++] = ft_strdup(unasigned);
	dup[i] = NULL;
	return (dup);
}

void	set_env_alpha(char *unasigned, int print, int fd)
{
	char	**exp;
	char	*temp;
	int		i;

	i = 0;
	temp = NULL;
	if (unasigned)
	{
		while (unasigned[i])
			i++;
	}
	exp = copy_env(unasigned, i);
	sort_alpha(0, 0, exp, temp);
	if (print)
		print_env(fd, exp);
}

void	execute_export(int fd, char *name, char *value)
{
	g_global.last_ret = 0;
	if (value == NULL && name == NULL)
		set_env_alpha(name, 1, fd);
	else if (value == NULL && name)
		set_env_alpha(name, 0, fd);
	else
	{
		if (get_var_index(name) == -1)
			add_var_in_env(name, value, 0);
		else
		{
			execute_unset(name);
			add_var_in_env(name, value, 0);
		}
	}
}
