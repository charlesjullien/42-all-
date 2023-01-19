/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_redirections_pipe.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:47:15 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:55:30 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*lex_pipe(t_cmd *lex, int x, int *i)
{
	*i = *i + 1;
	lex[x - 1].sep = '|';
	lex[x - 1].tab = malloc(sizeof(char) * 2);
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	lex[x - 1].tab[0] = '|';
	lex[x - 1].tab[1] = '\0';
	return (lex);
}

t_cmd	*lex_red_in(t_cmd *lex, int x, int *i)
{
	*i = *i + 1;
	lex[x - 1].sep = '<';
	lex[x - 1].tab = malloc(sizeof(char) * 2);
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	lex[x - 1].tab[0] = '<';
	lex[x - 1].tab[1] = '\0';
	return (lex);
}

t_cmd	*lex_red_out(t_cmd *lex, int x, int *i)
{
	*i = *i + 1;
	lex[x - 1].sep = '>';
	lex[x - 1].tab = malloc(sizeof(char) * 2);
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	lex[x - 1].tab[0] = '>';
	lex[x - 1].tab[1] = '\0';
	return (lex);
}

t_cmd	*lex_red_double_in(t_cmd *lex, int x, int *i)
{
	*i = *i + 2;
	lex[x - 1].sep = '<';
	lex[x - 1].tab = malloc(sizeof(char) * 3);
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	lex[x - 1].tab[0] = '<';
	lex[x - 1].tab[1] = '<';
	lex[x - 1].tab[2] = '\0';
	return (lex);
}

t_cmd	*lex_red_double_out(t_cmd *lex, int x, int *i)
{
	*i = *i + 2;
	lex[x - 1].sep = '>';
	lex[x - 1].tab = malloc(sizeof(char) * 3);
	if (lex[x - 1].tab == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	lex[x - 1].tab[0] = '>';
	lex[x - 1].tab[1] = '>';
	lex[x - 1].tab[2] = '\0';
	return (lex);
}
