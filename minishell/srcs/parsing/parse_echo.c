/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:36:06 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:15:08 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_length_space(char *str, int i)
{
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == ' ')
			break ;
		i++;
	}
	return (i + 1);
}

char	*ft_cpy_var(char *tmp, char *var, int *t, int *length_str)
{
	char	*value;
	int		i;

	value = NULL;
	*length_str = *length_str + ft_strlen(var);
	value = malloc(sizeof(char) * *length_str);
	if (value == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	i = -1;
	while (++i < *t)
		value[i] = tmp[i];
	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	while (var[++i])
	{
		value[*t] = var[i];
		*t = *t + 1;
	}
	free(tmp);
	return (value);
}

char	*ft_cpy_itoa(char *tmp, char *ito, int *t, int *length_str)
{
	char	*value;
	int		i;

	value = NULL;
	*length_str = *length_str + ft_strlen(ito);
	value = malloc(sizeof(char) * *length_str);
	if (value == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	i = -1;
	while (++i < *t)
		value[i] = tmp[i];
	i = -1;
	while (ito[++i])
	{
		value[*t] = ito[i];
		*t = *t + 1;
	}
	free(ito);
	free(tmp);
	return (value);
}

char	*find_env_var(char *name_var, char *tmp, int *t, int *length_str)
{
	size_t	i;
	int		size;

	i = 0;
	size = ft_strlen(name_var);
	if (name_var[0] == '?')
		return (ft_cpy_itoa(tmp, ft_itoa(g_global.last_ret), t, length_str));
	while (g_global.env[i])
	{
		if (!ft_strncmp(name_var, g_global.env[i], size))
		{
			tmp = ft_cpy_var(tmp, g_global.env[i], t, length_str);
			if (tmp == NULL)
				return (NULL);
			break ;
		}
		i++;
	}
	return (tmp);
}

char	*check_variable2(char **str, t_var *v, int *length_str)
{
	v->name_var = malloc(sizeof(char)
			* (find_length_space(*str, v->i) - v->i) + 1);
	if (v->name_var == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	v->i = v->i + 1;
	v->j = 0;
	while (str[0][v->i] && str[0][v->i] != ' ' && str[0][v->i] != '$')
	{
		v->name_var[v->j] = str[0][v->i];
		v->j++;
		v->i = v->i + 1;
	}
	v->name_var[v->j] = '\0';
	v->tmp = find_env_var(v->name_var, v->tmp, &v->t, length_str);
	if (!str[0][v->i])
	{
		v->tmp[v->t] = '\0';
		free(*str);
		str[0] = NULL;
		free(v->name_var);
		v->name_var = NULL;
		return (v->tmp);
	}
	return (v->tmp);
}
