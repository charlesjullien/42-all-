/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:03:59 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/02 19:57:44 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_data *d)
{
	if (d->a[0] > d->a[1])
		op_sa(d);
}

void	sort_three(t_data *d)
{
	if (d->a[0] > d->a[1] && d->a[2] > d->a[0])
		op_sa(d);
	else if (d->a[0] > d->a[1] && d->a[1] > d->a[2])
	{
		op_sa(d);
		op_rra(d);
	}
	else if (d->a[0] > d->a[1] && d->a[0] > d->a[2])
		op_ra(d);
	else if (d->a[2] < d->a[1] && d->a[2] > d->a[0])
	{
		op_sa(d);
		op_ra(d);
	}
	else if (d->a[0] < d->a[1] && d->a[0] > d->a[2])
		op_rra(d);
}

void	sort_four(t_data *d)
{
	op_pb(d);
	sort_three(d);
	op_pa(d);
	if (d->a[0] == d->min)
		return ;
	else if (d->a[0] == d->max)
		op_ra(d);
	else if (d->a[0] > d->a[1] && d->a[0] > d->a[2])
	{
		op_rra(d);
		op_sa(d);
		op_ra(d);
		op_ra(d);
	}
	else if (d->a[0] > d->a[1] && d->a[0] < d->a[2])
		op_sa(d);
}

void	sort_five2(t_data *d)
{
	long long	big_a;

	big_a = d->a[2];
	while (d->len_b != 0)
	{
		if (d->len_b == 2 && d->b[1] < d->a[0])
		{
			op_sb(d);
			op_pa(d);
		}
		if (d->b[0] < d->a[0])
			op_pa(d);
		if (d->len_b)
		{
			if (d->a[0] == big_a)
			{
				op_ra(d);
				break ;
			}
			op_ra(d);
		}
	}
}

void	sort_five(t_data *d)
{
	op_pb(d);
	op_pb(d);
	sort_three(d);
	sort_five2(d);
	if (d->len_b)
	{
		op_pa(d);
		if (d->len_b)
		{
			if (d->b[0] < d->a[0])
				op_pa(d);
			else
			{
				op_ra(d);
				op_pa(d);
			}
		}
	}
	sorted_push_min_first(d);
}
