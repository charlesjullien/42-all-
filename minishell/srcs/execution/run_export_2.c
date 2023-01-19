/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_export_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:09:38 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 18:17:23 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sort_alpha(int i, int j, char **exp, char *temp)
{
	while (exp[i])
	{
		j = i + 1;
		while (exp[j])
		{
			if (ft_strncmp(exp[i], exp[j], ft_strlen(exp[i])) > 0)
			{
				temp = ft_strdup(exp[i]);
				exp[i] = ft_strdup(exp[j]);
				exp[j] = ft_strdup(temp);
			}
			j++;
		}
		i++;
	}
}
