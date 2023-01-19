/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:00:50 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/08 08:52:13 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atoi(char *str, int *j)
{
	int			i;
	int			sign;
	long int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	*j = *j + i;
	return (nb * sign);
}

void	get_len(t_data *d, int ac, char **av, int i)
{
	int	j;

	j = 0;
	d->len = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && is_invalid(av[i]) == 0)
		{
			if (is_invalid(&av[i][j]))
				ft_quit(d);
			if (av[i][j] == '-')
				j++;
			if (ft_isdigit(av[i][j]))
				d->len++;
			while (ft_isdigit(av[i][j]))
				j++;
			while (ft_is_space(av[i][j]))
				j++;
		}
		i++;
	}
	d->len_a = d->len;
	d->len_b = 0;
}

void	parser(t_data *d, int ac, char **av)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && is_invalid(av[i]) == 0 && k < d->len)
		{
			if (is_invalid(&av[i][j]))
				ft_quit(d);
			d->a[k] = ft_atoi(&av[i][j], &j);
			if (d->a[k] < -2147483648 || d->a[k] > 2147483647)
				ft_quit(d);
			while (ft_is_space(av[i][j]))
				j++;
			k++;
		}
		i++;
	}
}
