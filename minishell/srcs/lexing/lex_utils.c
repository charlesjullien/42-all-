/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:47:27 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 13:31:56 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_sep(char c, char n)
{
	if (n)
	{
		if (c == '\'' || c == '\"' || c == '|' || c == '<'
			|| c == '>' || (c == '<' && n == '<')
			|| (c == '>' && n == '>'))
			return (1);
	}
	else
	{
		if (c == '\'' || c == '\"' || c == '|' || c == '<' || c == '>')
			return (1);
	}
	return (0);
}

int	check_pr(char c, char n)
{
	if (c == '|' || c == '<' || c == '>'
		|| (c == '<' && n == '<') || (c == '>' && n == '>'))
		return (1);
	return (0);
}

void	find_index_quotes(char *line, int *i)
{
	char	c;

	while (line[*i] && line[*i] != ' ' && !check_pr(line[*i], line[*i + 1]))
	{
		if (line[*i] == '\"' || line[*i] == '\'')
		{
			c = line[*i];
			*i = *i + 1;
			while (line[*i] && line[*i] != c)
				*i = *i + 1;
		}
		if (!line[*i] || !line[*i + 1] || line[*i + 1] == ' ')
			break ;
		*i = *i + 1;
	}
	if (!line[*i])
	{
		ft_putstr_fd("unclosed quotes\n", 0);
		exit(1);
	}
}
