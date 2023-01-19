/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:35:55 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/26 15:46:14 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	parse_cd(t_cmd *lex, int x, int *i, int *fd)
{
	char	*path;
	int		j;

	j = 0;
	*i = *i + 1;
	if (*i >= x)
		return ;
	path = malloc(sizeof(char) * (ft_strlen(lex[*i].tab) + 1));
	if (path == NULL)
		ft_exit(lex, "Warning : Malloc failed\n");
	while (lex[*i].tab[j])
	{
		path[j] = lex[*i].tab[j];
		j++;
	}
	path[j] = '\0';
	if (!ft_strlen(path))
		return ;
	*i = *i + 1;
	while (*i < x && !parse_builtin(lex, *i))
		*i = *i + 1;
	execute_cd(path, *fd);
}
