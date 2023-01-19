/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:47:05 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:54:13 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_backslash(char c, char n)
{
	if (!n)
		return (0);
	if (c == '\\' && n != ' ')
		return (1);
	return (0);
}

void	no_sep_more(char *line, int *i)
{
	if (line[*i + 1] && line[*i] == '\\'
		&& is_backslash(line[*i], line[*i + 1]))
		*i = *i + 2;
	else
		*i = *i + 1;
}

t_cmd	*no_sep(t_cmd *lex, int j, char *line, int *i)
{
	int		ind;

	lex[lex[0].x - 1].sep = ' ';
	while (line[*i] && line[*i] != ' ' && !check_sep(line[*i], line[*i + 1]))
		no_sep_more(line, i);
	lex[lex[0].x - 1].tab = malloc(sizeof(char) * (*i - j + 1));
	if (lex[lex[0].x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	ind = 0;
	while (j < *i && !check_pr(line[j], line[j + 1]))
	{
		if (line[j] != '\\')
			lex[lex[0].x - 1].tab[ind++] = line[j++];
		else
			j++;
	}
	lex[lex[0].x - 1].tab[ind] = '\0';
	if (line[*i] && line[*i] == ' ' && line[*i + 1] && line[*i + 1] != '|'
		&& line[*i + 1] != '<' && line[*i + 1] != '>')
		lex[lex[0].x - 1].next_space = 1;
	if (line[*i] && !check_sep(line[*i], line[*i + 1]))
		*i = *i + 1;
	return (lex);
}

t_cmd	*simple_quotes(t_cmd *lex, int x, char *line, int *i)
{
	int		j;
	int		ind;

	*i = *i + 1;
	j = *i;
	lex[x - 1].sep = '\'';
	while (line[*i] && line[*i] != '\'')
		*i = *i + 1;
	lex[x - 1].tab = malloc(sizeof(char) * (*i - j + 1));
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	ind = 0;
	while (j < *i)
		lex[x - 1].tab[ind++] = line[j++];
	lex[x - 1].tab[ind] = '\0';
	if (line[*i] && line[*i] == '\'' && line[*i + 1] == ' ')
		lex[x - 1].next_space = 1;
	if (!line[*i] || line[*i] != '\'')
	{
		printf("minishell: simple quotes unclosed\n");
		return (NULL);
	}
	*i = *i + 1;
	return (lex);
}
