/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:33:51 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/16 14:43:47 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_dodo(t_data *d, long long locked_time)
{
	long long	start_time;

	start_time = 0;
	start_time = lock_time(d);
	while (lock_time(d) - start_time < locked_time)
		usleep(locked_time / 10);
}

void	print_activity(t_data *d, char *str, int id)
{
	pthread_mutex_lock(&d->e);
	if (d->dead != 0)
	{
		pthread_mutex_unlock(&d->e);
		return ;
	}
	else
	{
		pthread_mutex_lock(&d->printer);
		printf("%lli ms : %i %s\n", get_time_milisec()
			- d->starter_time, (id + 1), str);
		pthread_mutex_unlock(&d->printer);
	}
	pthread_mutex_unlock(&d->e);
}

long long	get_time_milisec(void)
{
	struct timeval	curr_time;
	long long		time;

	time = 0;
	if (gettimeofday(&curr_time, NULL) == -1)
	{
		ft_putstr_fd("Error : gettimeofday function failed (ret -1)", 2);
		return (FALSE);
	}
	time = (curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000);
	return (time);
}

long long	lock_time(t_data *d)
{
	long long	ret;

	pthread_mutex_lock(&(d->c));
	ret = get_time_milisec();
	pthread_mutex_unlock(&(d->c));
	return (ret);
}
