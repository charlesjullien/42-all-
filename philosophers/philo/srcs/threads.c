/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:32:40 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/19 19:52:19 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	death_checker(t_curr_philosopher *cp, t_data *d, int i)
{
	while (d->all_fed == 0)
	{
		i = 0;
		while (d->dead == 0 && i < d->nb_ph)
		{
			pthread_mutex_lock(&(d->a));
			if ((get_time_milisec() - cp[i].recent_meal) > d->time_to_die)
			{
				print_activity(d, "died", i);
				pthread_mutex_lock(&(d->e));
				d->dead = 1;
				pthread_mutex_unlock(&(d->e));
			}
			pthread_mutex_unlock(&(d->a));
			i++;
		}
		i = 0;
		if (d->dead == 1)
			break ;
		death_checker_2(cp, d, i);
	}
}

void	having_dinner_2(t_curr_philosopher *cp, t_data *d)
{
	print_activity(d, "is eating", cp->index);
	pthread_mutex_lock(&(d->a));
	cp->recent_meal = lock_time(d);
	pthread_mutex_unlock(&(d->a));
	philo_dodo(d, d->time_to_eat);
	pthread_mutex_lock(&(d->c));
	cp->meals++;
	pthread_mutex_unlock(&(d->c));
	pthread_mutex_unlock(&(d->forks[cp->left_fork]));
	pthread_mutex_unlock(&(d->forks[cp->right_fork]));
}

void	having_dinner(t_curr_philosopher *cp)
{
	t_data	*d;

	d = cp->d;
	if ((cp->index + 1) % 2 == 0)
	{
		pthread_mutex_lock(&(d->forks[cp->left_fork]));
		print_activity(d, "has taken a fork", cp->index);
		pthread_mutex_lock(&(d->forks[cp->right_fork]));
		print_activity(d, "has taken a fork", cp->index);
	}
	else
	{
		pthread_mutex_lock(&(d->forks[cp->right_fork]));
		print_activity(d, "has taken a fork", cp->index);
		pthread_mutex_lock(&(d->forks[cp->left_fork]));
		print_activity(d, "has taken a fork", cp->index);
	}
	having_dinner_2(cp, d);
}

void	*dinner_starter(void *curr_philo)
{
	t_data				*d;
	t_curr_philosopher	*cp;

	cp = curr_philo;
	d = cp->d;
	if (cp->index % 2)
		philo_dodo(d, (d->time_to_eat / 10));
	pthread_mutex_lock(&(d->a));
	while (d->nb_ph != 1 && !(d->dead))
	{
		pthread_mutex_unlock(&(d->a));
		having_dinner(cp);
		pthread_mutex_lock(&(d->b));
		if (d->all_fed)
		{
			pthread_mutex_unlock(&(d->b));
			return (NULL);
		}
		dinner_starter_2(d, cp->index);
	}
	pthread_mutex_unlock(&(d->a));
	return (NULL);
}

int	dinner_create(t_data *d, int i)
{
	t_curr_philosopher	*cp;

	cp = d->curr_philo;
	d->starter_time = get_time_milisec();
	while (i < d->nb_ph)
	{
		if (pthread_create(&(cp[i].thread_index), NULL,
				dinner_starter, &(cp[i])))
			return (FALSE);
		pthread_mutex_lock(&(d->a));
		cp[i].recent_meal = lock_time(d);
		pthread_mutex_unlock(&(d->a));
		i++;
	}
	death_checker(d->curr_philo, d, 0);
	return (TRUE);
}
