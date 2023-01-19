/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:33:36 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/13 14:15:40 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	check_str(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (i == 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (check_str(str))
		return (-100);
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res = res * sign;
	return ((int)res);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
