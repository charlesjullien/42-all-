/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:42:41 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 16:49:42 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_strs(char **big, char	*small)
{
	int	i;

	i = 0;
	if (big)
	{
		while (big[i])
		{
			free(big[i]);
			i++;
		}
		free(big);
	}
	if (small)
		free(small);
}
