/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:02:52 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:59:24 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_var_value(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (g_global.env[i])
	{
		j = 0;
		while (g_global.env[i][j] == str[j])
			j++;
		if (ft_strlen(str) == j && g_global.env[i][j + 1])
			return (&g_global.env[i][j + 1]);
		i++;
	}
	return (str);
}

char	*get_pwd(void)
{
	char	buf[4096];
	char	*pwd;

	pwd = malloc(sizeof(char) * ft_strlen(get_var_value("PWD")));
	if (!pwd)
		ft_exit(NULL, "Warning : Malloc failed\n");
	if (getcwd(buf, 4096) == 0)
	{		
		pwd = get_var_value("PWD");
		return (pwd);
	}
	return (ft_strdup(buf));
}

void	redefine_env2(char *temp, int k, int i, char *new_value)
{
	temp[k] = '=';
	free(g_global.env[i]);
	g_global.env[i] = NULL;
	g_global.env[i] = ft_strjoin(temp, new_value);
}

void	redefine_env(char *name, char *new_value, int i, int k)
{
	int		j;
	char	*temp;

	while (g_global.env[i])
	{
		j = 0;
		while (g_global.env[i][j] == name[j])
			j++;
		if (ft_strlen(name) == j)
		{
			temp = malloc(sizeof(char) * j + 1);
			if (!temp)
				ft_exit(NULL, "Warning : Malloc failed\n");
			while (k != j)
			{
				temp[k] = g_global.env[i][k];
				k++;
			}
			redefine_env2(temp, k, i, new_value);
			return ;
		}
		i++;
	}
}
