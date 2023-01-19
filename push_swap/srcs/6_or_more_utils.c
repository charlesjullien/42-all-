/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_or_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:57:02 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/02 12:05:58 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_nb_moves(t_data *d)
{
	d->moves_min = d->len_b - d->index_min;
	d->dir_min = 1;
	if (d->index_min < d->len_b / 2)
	{
		d->moves_min = d->index_min;
		d->dir_min = 0;
	}
	d->moves_max = d->len_b - d->index_max;
	d->dir_max = 1;
	if (d->index_max < d->len_b / 2)
	{
		d->moves_max = d->index_max;
		d->dir_max = 0;
	}
}

void	get_chunks(t_data *d)
{
	long	i;
	long	count;

	i = 0;
	d->chunks = d->len / 80;
	if (d->len % 80)
		d->chunks++;
	d->med = malloc(sizeof(long) * d->chunks);
	d->med_len = malloc(sizeof(long) * d->chunks);
	if (!d->med || !d->med_len)
		ft_quit(d);
	d->med[d->chunks - 1] = d->max;
	while (i < d->chunks - 1)
	{
		count = d->len / d->chunks;
		if (i == 0)
			count += d->len % d->chunks;
		if (i == 0)
			d->med[i] = d->sorted[count - 1];
		else
			d->med[i] = d->sorted[(count + (d->len % d->chunks) - 1)
				+ (count - 1) * i];
		i++;
	}
}
