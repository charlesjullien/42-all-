/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:36:47 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 16:31:22 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_name_uns(t_cmd *lex, int *i)
{
	char	*name;
	int		j;

	name = malloc(sizeof(char) * (ft_strlen(lex[*i].tab) + 1));
	if (name == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	j = 0;
	while (lex[*i].tab[j])
	{
		name[j] = lex[*i].tab[j];
		j++;
	}
	name[j] = '\0';
	*i = *i + 1;
	return (name);
}

void	parse_unset(t_cmd *lex, int x, int *i)
{
	char	*name;

	name = NULL;
	*i = *i + 1;
	while (*i < x)
	{
		while (*i < x && parse_builtin(lex, *i) > 8)
			*i = *i + 2;
		if (*i >= x || parse_builtin(lex, *i) > 8)
			break ;
		name = find_name_uns(lex, i);
		if (name == NULL)
			return ;
		execute_unset(name);
		free(name);
	}
}
