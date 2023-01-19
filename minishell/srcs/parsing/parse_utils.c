/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:36:57 by cjullien          #+#    #+#             */
/*   Updated: 2022/01/19 13:51:05 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strcmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) < ft_strlen(s2) || ft_strlen(s1) > ft_strlen(s2))
		return (1);
	if (n == 0)
		return (0);
	while (s1[i] && i < n - 1)
	{
		if (s1[i] != s2[i] && s1[i] != (s2[i] - 32))
			return (1);
		i++;
	}
	return (0);
}
