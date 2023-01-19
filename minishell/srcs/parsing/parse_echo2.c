/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_echo2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:49:49 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 15:53:14 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_variable_more(char *tmp, char *str, int *i, int *t)
{
	tmp[*t] = str[*i];
	*t = *t + 1;
	*i = *i + 1;
}

char	*check_variable(char *str, int i)
{
	t_var	v;
	int		length_str;

	v.i = i;
	v.t = 0;
	v.name_var = NULL;
	length_str = ft_strlen(str) + 1;
	v.tmp = malloc(sizeof(char) * length_str);
	if (v.tmp == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	while (str[v.i])
	{
		if (str[v.i] == '$' && str[v.i + 1] && str[v.i + 1] != ' ')
			v.tmp = check_variable2(&str, &v, &length_str);
		else
			check_variable_more(v.tmp, str, &v.i, &v.t);
		if (str == NULL)
			break ;
	}
	v.tmp[v.t] = '\0';
	if (v.name_var != NULL)
		free(v.name_var);
	free(str);
	return (v.tmp);
}

char	*parse_echo_more(t_cmd *lex, char *str, char *tmp, int *i)
{
	tmp = ft_strjoin(str, lex[*i].tab);
	free(str);
	str = tmp;
	if (lex[*i].next_space == 1)
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = tmp;
	}
	return (str);
}

char	*parse_echo2(t_cmd *lex, char *str, char *tmp, int *i)
{
	str = ft_strdup(lex[*i].tab);
	if (lex[*i].next_space == 1)
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = tmp;
	}
	return (str);
}

void	parse_echo(t_cmd *lex, const int x, int *i, int *fd)
{
	char	*str;
	char	*tmp;

	str = NULL;
	tmp = NULL;
	*i = *i + 1;
	if (*i >= x || parse_builtin(lex, *i) == 8)
		ft_putchar_fd('\n', 0);
	while (*i < x && (parse_builtin(lex, *i) < 8 || parse_builtin(lex, *i) > 8))
	{
		if (parse_builtin2(lex, *i) > 8)
			*i = *i + 2;
		else
		{
			if (lex[*i].sep != '\'')
				lex[*i].tab = check_variable(lex[*i].tab, 0);
			if (str == NULL)
				str = parse_echo2(lex, str, tmp, i);
			else if (lex[*i].tab != NULL && str != NULL)
				str = parse_echo_more(lex, str, tmp, i);
			*i = *i + 1;
		}
	}
	if (str != NULL)
		execute_echo(str, *fd);
}
