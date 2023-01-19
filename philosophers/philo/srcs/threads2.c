/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:10:23 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/19 19:51:17 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	all_ate(t_data *d, t_curr_philosopher *cp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < d->nb_ph)
	{
		count = count + cp[i].meals;
		i++;
	}
	if (count == d->nb_ph * d->time_must_eat)
		return (1);
	return (0);
}

void	dinner_starter_2(t_data *d, int i)
{
	pthread_mutex_unlock(&(d->b));
	print_activity(d, "is sleeping", i);
	philo_dodo(d, d->time_to_sleep);
	print_activity(d, "is thinking", i);
	pthread_mutex_lock(&(d->a));
}

void	death_checker_2(t_curr_philosopher *cp, t_data *d, int i)
{
	pthread_mutex_lock(&(d->a));
	pthread_mutex_lock(&(d->c));
	pthread_mutex_lock(&(d->b));
	while (i < d->nb_ph && cp[i].meals >= d->time_must_eat - 1
		&& d->time_must_eat != -1)
	{
		if (all_ate(d, cp))
			break ;
		i++;
	}
	if (cp[i].meals == 0 && d->time_must_eat == 1 && d->nb_ph == 1)
		i = 0;
	if (d->nb_ph == i)
		d->all_fed = 1;
	pthread_mutex_unlock(&(d->a));
	pthread_mutex_unlock(&(d->b));
	pthread_mutex_unlock(&(d->c));
}
