/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:36:25 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:29:07 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_name_exp(t_cmd *lex, int *i, int *equal)
{
	char	*name;
	int		j;

	name = malloc(sizeof(char) * (ft_strlen(lex[*i].tab) + 1));
	if (name == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	j = 0;
	while (lex[*i].tab[j])
	{
		if (lex[*i].tab[j] == '=')
			break ;
		name[j] = lex[*i].tab[j];
		j++;
	}
	name[j] = '\0';
	if (!lex[*i].tab[j] || (lex[*i].tab[j] == '=' && !lex[*i].tab[j + 1]))
		*i = *i + 1;
	else if (lex[*i].tab[j] == '=')
		*equal = 1;
	return (name);
}

char	*find_value_exp2(t_cmd *lex, int *i, char *value, t_int *in)
{
	char	c;

	if (lex[*i].tab[in->j] == '\"' || lex[*i].tab[in->j] == '\'')
	{
		c = lex[*i].tab[in->j];
		while (lex[*i].tab[in->j] && lex[*i].tab[in->j] != c)
		{
			value[in->v] = lex[*i].tab[in->j];
			in->j = in->j + 1;
			in->v = in->v + 1;
		}
	}
	return (value);
}

char	*find_value_exp(t_cmd *lex, int *i, int *equal)
{
	char	*value;
	t_int	in;

	in.j = 0;
	while (lex[*i].tab[in.j] && lex[*i].tab[in.j] != '=' && *equal == 1)
		in.j++;
	if (lex[*i].tab[in.j] == '=')
		in.j++;
	if (!lex[*i].tab[in.j])
		return (NULL);
	value = malloc(sizeof(char) * (ft_strlen(lex[*i].tab) + 1));
	if (value == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	in.v = 0;
	while (lex[*i].tab[in.j])
	{
		value = find_value_exp2(lex, i, value, &in);
		if (!lex[*i].tab[in.j])
			break ;
		value[in.v++] = lex[*i].tab[in.j++];
	}
	value[in.v] = '\0';
	if (!lex[*i].tab[in.j])
		*i = *i + 1;
	return (value);
}

char	*take_off_spaces(char *value)
{
	int		i;
	int		j;
	char	*tmp;

	if (!value)
		return (NULL);
	tmp = malloc(sizeof(char) * (ft_strlen(value) + 1));
	if (tmp == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	j = 0;
	i = 0;
	while (value[i])
	{
		if (value[i] != ' ' || (value[i] == ' '
				&& value[i + 1] && value[i + 1] != ' '))
			tmp[j++] = value[i];
		i++;
	}
	tmp[j] = '\0';
	free(value);
	return (tmp);
}

void	parse_export(t_cmd *lex, char *name, int *i, int *fd)
{
	char	*value;
	int		equal;

	value = NULL;
	equal = 0;
	if (*i + 1 == lex[0].x)
		execute_export(*fd, name, value);
	*i = *i + 1;
	while (*i < lex[0].x)
	{
		while (*i < lex[0].x && parse_builtin(lex, *i) > 8)
			*i = *i + 2;
		if (*i >= lex[0].x || parse_builtin(lex, *i) == 8)
			break ;
		name = find_name_exp(lex, i, &equal);
		if (*i < lex[0].x)
			value = find_value_exp(lex, i, &equal);
		if (*i < lex[0].x)
			value = take_off_spaces(value);
		if (name == NULL || value == NULL)
			return ;
		execute_export(*fd, name, value);
		free(name);
		free(value);
	}
}
