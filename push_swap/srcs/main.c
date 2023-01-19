/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:52:55 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/08 08:52:28 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_data *d)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < d->len)
	{
		if (d->a[i] > d->a[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	get_out_of_range_num(t_data *d)
{
	long	i;

	i = 0;
	d->to_fill = -888888;
	while (i < d->len)
	{
		if (d->a[i] == d->to_fill)
		{
			d->to_fill++;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	while (i < d->len)
	{
		d->b[i] = d->to_fill;
		i++;
	}
}

void	sorter(t_data *d)
{
	get_out_of_range_num(d);
	copy_stacks(d);
	get_a_sorted(d);
	if (d->len <= 2)
		sort_two(d);
	else if (d->len == 3)
		sort_three(d);
	else if (d->len == 4)
		sort_four(d);
	else if (d->len == 5)
		sort_five(d);
	else
		sort_6_or_more(d);
}

void	struct_init(t_data *data)
{
	data->a = malloc(sizeof(long) * data->len);
	data->b = malloc(sizeof(long) * data->len);
	data->a_copy = malloc(sizeof(long) * data->len);
	data->b_copy = malloc(sizeof(long) * data->len);
	data->sorted = malloc(sizeof(long) * data->len);
	data->med = NULL;
	data->med_len = NULL;
	if (data->a == NULL || data->b == NULL || data->a_copy == NULL
		|| data->b_copy == NULL || data->sorted == NULL)
		ft_quit(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	if (check_argvs(ac, av) == 0)
		return (0);
	get_len(&data, ac, av, 1);
	struct_init(&data);
	parser(&data, ac, av);
	check_no_doublon(&data);
	if (is_sorted(&data))
	{
		i_want_to_be_free(&data);
		return (0);
	}
	get_min_max(&data);
	sorter(&data);
	i_want_to_be_free(&data);
	return (0);
}
