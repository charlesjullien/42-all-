/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:47:37 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:56:48 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*what_sep(t_cmd *lex, char *line, int *i)
{
	if (line[*i] == '\'')
		lex = simple_quotes(lex, lex[0].x, line, i);
	else if (line[*i] == '\"')
		lex = double_quotes(lex, lex[0].x, line, i);
	else if (line[*i] == '|')
		lex = lex_pipe(lex, lex[0].x, i);
	else if (line[*i] == '<' && line[*i + 1] && line[*i + 1] != '<')
		lex = lex_red_in(lex, lex[0].x, i);
	else if (line[*i] == '>' && line[*i + 1] && line[*i + 1] != '>')
		lex = lex_red_out(lex, lex[0].x, i);
	else if (line[*i] == '<' && line[*i + 1] && line[*i + 1] == '<')
		lex = lex_red_double_in(lex, lex[0].x, i);
	else if (line[*i] == '>' && line[*i + 1] && line[*i + 1] == '>')
		lex = lex_red_double_out(lex, lex[0].x, i);
	else
		lex = no_sep(lex, *i, line, i);
	return (lex);
}

int	useless_spaces(char *line, int *i)
{
	while (line[*i])
	{
		if (line[*i] != ' ' && line[*i] != '\t'
			&& line[*i] != '\r' && line[*i] != '\v'
			&& line[*i] != '\f')
			break ;
		*i = *i + 1;
	}
	if (line[*i])
		return (1);
	return (0);
}

int	should_break(char *line, int i, t_cmd *lex)
{
	if (lex == NULL)
		return (1);
	else if (!line[i])
		return (1);
	else if (line[i] && !line[i + 1] && line[i] != ' ')
		return (0);
	else if (!line[i + 1])
		return (1);
	return (0);
}

t_cmd	*init_lex(void)
{
	t_cmd	*lex;

	lex = malloc(sizeof(t_cmd));
	if (lex == NULL)
		ft_exit(NULL, "Warning : Malloc failed\n");
	lex[0].x = 1;
	return (lex);
}

int	lexing(char *line, int i)
{
	t_cmd	*lex;
	int		index;

	if (!useless_spaces(line, &i) || ft_strncmp("|", line, 5) == 0
		|| ft_strncmp("<", line, 5) == 0 || ft_strncmp(">", line, 5) == 0)
		return (0);
	lex = init_lex();
	i = 0;
	index = 0;
	while (line[i])
	{
		if (!useless_spaces(line, &i))
			break ;
		if (index != 0)
			lex = ft_realloc_lex(lex);
		lex = what_sep(lex, line, &i);
		if (should_break(line, i, lex))
			break ;
		index++;
	}
	if (lex)
		parcing(lex);
	if (lex)
		free_lex(lex);
	return (1);
}
