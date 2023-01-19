/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:04:01 by mabuchar          #+#    #+#             */
/*   Updated: 2021/01/12 17:24:43 by mabuchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_char_by_index(char *str, char c)
{
	char	*ch;

	ch = ft_strchr(str, c);
	if (!ch)
		return (-1);
	return ((size_t)(ch - str));
}
