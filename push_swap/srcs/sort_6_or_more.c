/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_or_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:03:42 by cjullien          #+#    #+#             */
/*   Updated: 2021/10/31 17:03:44 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_index_min_max(t_data *d, long min, long max)
{
	long	i;
	long	j;

	i = 0;
	j = 0;
	while (j < d->len_b)
	{
		if (i == 0)
		{
			min = d->b[j];
			max = d->b[j];
			d->index_min = i;
			d->index_max = i;
		}
		get_index_min_max_2(d, &min, &max, i);
		j++;
		i++;
	}
}

void	move_chunk_into_a(t_data *d, long *push)
{
	long	i;

	i = 0;
	while (d->len_b)
	{
		get_index_min_max(d, 0, 0);
		get_nb_moves(d);
		if (d->moves_min < d->moves_max)
		{
			d->dir_selected = d->dir_min;
			d->moves_selected = d->moves_min;
			d->index_selected = d->index_min;
		}
		else
		{
			d->dir_selected = d->dir_max;
			d->moves_selected = d->moves_max;
			d->index_selected = d->index_max;
			*push = *push + 1;
		}
		move_chunk_into_a_2(d);
	}
}

void	get_digit_at_top_of_a(t_data *d, long i)
{
	long	first_half;
	long	second_half;

	if (i != d->chunks - 1 && i != 0)
	{
		first_half = d->med_len[i - 1];
		second_half = d->len - d->med_len[i];
		if (first_half < second_half)
		{
			while (first_half > 0)
			{
				op_ra(d);
				first_half--;
			}
		}
		else
		{
			while (second_half > 0)
			{
				op_rra(d);
				second_half--;
			}
		}
	}
}

void	move_chunk_into_b(t_data *d, long n, long i)
{
	long	j;

	j = 0;
	if (i == 0)
		d->med_len[i] = 0;
	else
		d->med_len[i] = d->med_len[i - 1];
	while (n)
	{
		if (d->a[j] <= d->med[i])
		{
			op_pb(d);
			d->med_len[i]++;
		}
		else
			op_ra(d);
		n--;
	}
}

void	sort_6_or_more(t_data *d)
{
	long	i;
	long	n;
	long	push;

	i = 0;
	n = d->len;
	get_chunks(d);
	while (i < d->chunks)
	{
		push = 0;
		move_chunk_into_b(d, n, i);
		get_digit_at_top_of_a(d, i);
		move_chunk_into_a(d, &push);
		while (push && i < (d->chunks - 1))
		{
			op_ra(d);
			push = push - 1;
		}
		n = d->len - d->med_len[i];
		i++;
	}
	sorted_push_min_first(d);
}
