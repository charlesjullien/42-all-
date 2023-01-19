/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:56:26 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/02 13:20:06 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	copy_stacks(t_data *d)
{
	long	i;

	i = 0;
	while (i < d->len)
	{
		d->a_copy[i] = d->a[i];
		d->b_copy[i] = d->b[i];
		i++;
	}
}

void	get_min_max(t_data *d)
{
	long	i;

	i = 0;
	d->min = d->a[0];
	d->max = d->a[0];
	while (i < d->len)
	{
		if (d->a[i] < d->min)
			d->min = d->a[i];
		if (d->a[i] > d->max)
			d->max = d->a[i];
		i++;
	}
}

void	sorted_push_min_first(t_data *d)
{
	long	i;
	long	n;

	i = 0;
	n = d->len / 2;
	while (d->a[i] != d->min)
		i++;
	if (i > (n + 1))
	{
		while (i < d->len)
		{
			op_rra(d);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			op_ra(d);
			i--;
		}
	}
}

void	get_a_sorted(t_data *d)
{
	long	i;
	long	j;

	i = 0;
	while (i < d->len)
	{
		d->sorted[i] = d->a[i];
		i++;
	}
	i = 0;
	while (i < d->len - 1)
	{
		j = i + 1;
		while (j < d->len)
		{
			if (d->sorted[i] > d->sorted[j])
				ft_swap(&d->sorted[i], &d->sorted[j]);
			j++;
		}
		i++;
	}
}
