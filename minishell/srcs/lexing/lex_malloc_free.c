/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_malloc_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:46:54 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:52:02 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_lex(t_cmd *lex, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		printf("print lex : ");
		printf("(%c) ", lex[i].sep);
		printf("[%s] ", lex[i].tab);
		printf("\n");
		i++;
	}
}

void	free_lex(t_cmd *lex)
{
	int	i;

	i = 0;
	while (i < lex[0].x)
	{
		free(lex[i].tab);
		i++;
	}
	free(lex);
}

t_cmd	*ft_realloc_lex(t_cmd *lex)
{
	int		i;
	int		tmp_x;
	t_cmd	*tmp;

	tmp_x = lex[0].x + 1;
	i = -1;
	tmp = NULL;
	tmp = malloc(sizeof(t_cmd) * (tmp_x));
	if (tmp == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	tmp[0].x = tmp_x;
	while (++i < tmp[0].x - 1)
	{
		tmp[i].sep = lex[i].sep;
		tmp[i].next_space = lex[i].next_space;
		if (lex[i].tab)
			tmp[i].tab = ft_strdup(lex[i].tab);
	}
	tmp[i].sep = 'n';
	tmp[i].next_space = 0;
	tmp[i].tab = NULL;
	free_lex(lex);
	return (tmp);
}
