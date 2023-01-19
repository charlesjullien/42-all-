/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:41:05 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/15 21:05:48 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	setup_philos(t_data *d, int count)
{
	d->curr_philo = malloc(sizeof(t_curr_philosopher) * d->nb_ph);
	if (d->curr_philo == NULL)
		return (FALSE);
	memset(d->curr_philo, 0, (size_t)(sizeof(t_curr_philosopher) * d->nb_ph));
	while (count >= 0)
	{
		d->curr_philo[count].recent_meal = 0;
		d->curr_philo[count].meals = 0;
		d->curr_philo[count].d = d;
		d->curr_philo[count].left_fork = count;
		d->curr_philo[count].right_fork = (count + 1) % d->nb_ph;
		d->curr_philo[count].index = count;
		count--;
	}
	return (TRUE);
}

int	setup_mutex(t_data *d, int count)
{
	d->forks = malloc(sizeof(pthread_mutex_t) * d->nb_ph);
	if (d->forks == NULL)
		return (0);
	memset(d->forks, 0, (size_t)(sizeof(pthread_mutex_t) * d->nb_ph));
	while (count >= 0)
	{
		if (pthread_mutex_init(&(d->forks[count]), NULL) != 0)
			return (FALSE);
		count--;
	}
	if (pthread_mutex_init(&(d->a), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(d->printer), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(d->b), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(d->c), NULL) != 0)
		return (FALSE);
	if (pthread_mutex_init(&(d->e), NULL) != 0)
		return (FALSE);
	return (TRUE);
}

int	contains_error_2(t_data *d)
{
	if (d->time_must_eat < -1)
	{
		ft_putstr_fd("Error : times_each_philo_must_eat is invalid\n", 2);
		return (TRUE);
	}
	return (FALSE);
}

int	contains_error(t_data *d)
{
	if (d->nb_ph < 1 || d->nb_ph > INT_MAX)
	{
		ft_putstr_fd("Error : nb_of_philosophers is invalid\n", 2);
		return (TRUE);
	}
	if (d->time_to_die < 0 || d->time_to_die > INT_MAX)
	{
		ft_putstr_fd("Error : max_time_till_death is invalid\n", 2);
		return (TRUE);
	}
	if (d->time_to_eat < 0 || d->time_to_eat > INT_MAX)
	{
		ft_putstr_fd("Error : time_to_eat is invalid\n", 2);
		return (TRUE);
	}
	if (d->time_to_sleep < 0 || d->time_to_sleep > INT_MAX)
	{
		ft_putstr_fd("Error : time_to_sleep is invalid\n", 2);
		return (TRUE);
	}
	if (contains_error_2(d))
		return (TRUE);
	return (FALSE);
}

int	struct_init(t_data *d, char **av)
{
	d->nb_ph = -1;
	d->time_must_eat = -1;
	d->time_to_die = -1;
	d->time_to_eat = -1;
	d->time_to_sleep = -1;
	d->all_fed = 0;
	d->dead = 0;
	d->nb_ph = ft_atoi(av[1]);
	d->time_to_die = ft_atoi(av[2]);
	d->time_to_eat = ft_atoi(av[3]);
	d->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		d->time_must_eat = ft_atoi(av[5]);
	if (contains_error(d) == TRUE)
		return (0);
	if (setup_mutex(d, (d->nb_ph - 1)) == FALSE
		|| setup_philos(d, (d->nb_ph - 1)) == FALSE)
	{
		ft_putstr_fd("Error : Mutex or tab struct malloc creation failed\n", 2);
		return (0);
	}
	return (1);
}
