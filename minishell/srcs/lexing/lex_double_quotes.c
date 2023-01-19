/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_double_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 22:51:33 by mabuchar          #+#    #+#             */
/*   Updated: 2022/01/30 22:51:38 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*double_quotes_more(t_cmd *lex, int *j, int *ind, char *line)
{
	if (line[*j] == '\\' && line[*j + 1] && (line[*j + 1] == '$'
			|| line[*j + 1] == '\'' || line[*j + 1] == '\"'
			|| line[*j + 1] == '\\'))
	{
		*j = *j + 1;
		lex[lex[0].x - 1].tab[*ind] = line[*j];
		*j = *j + 1;
		*ind = *ind + 1;
	}
	else
	{
		lex[lex[0].x - 1].tab[*ind] = line[*j];
		*j = *j + 1;
		*ind = *ind + 1;
	}
	return (lex);
}

void	double2(char *line, int *i)
{
	if (line[*i + 1] && line[*i] == '\\' && (line[*i + 1] == '\\'
			|| line[*i + 1] == '\"' || line[*i + 1] == '$'))
		*i = *i + 2;
	else
		*i = *i + 1;
}

t_cmd	*double_quotes(t_cmd *lex, int x, char *line, int *i)
{
	int		j;
	int		ind;

	*i = *i + 1;
	j = *i;
	lex[x - 1].sep = '\"';
	while (line[*i] && line[*i] != '\"')
		double2(line, i);
	lex[x - 1].tab = malloc(sizeof(char) * (*i - j + 1));
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	ind = 0;
	while (j < *i)
		lex = double_quotes_more(lex, &j, &ind, line);
	lex[x - 1].tab[ind] = '\0';
	if (line[*i] && line[*i] == '\"' && line[*i + 1] == ' ')
		lex[x - 1].next_space = 1;
	if (!line[*i] || line[*i] != '\"')
		printf("minishell: double quotes unclosed\n");
	if (!line[*i] || line[*i] != '\"')
		return (NULL);
	*i = *i + 1;
	return (lex);
}
