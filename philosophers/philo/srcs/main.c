/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:33:21 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/16 14:44:13 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_memory(t_data *d, int i)
{
	while (i < d->nb_ph)
	{
		pthread_join(d->curr_philo[i].thread_index, NULL);
		i++;
	}
	i = 0;
	while (i < d->nb_ph)
	{
		pthread_mutex_destroy(&d->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&d->printer);
	pthread_mutex_destroy(&d->a);
	pthread_mutex_destroy(&d->b);
	pthread_mutex_destroy(&d->c);
	pthread_mutex_destroy(&d->e);
	free(d->curr_philo);
	free(d->forks);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
	{
		printf("Model :\n./philo nb_of_philosophers max_time_till_death \
time_to_eat time_to_sleep (option:)number_of_time_each_philo_must_eat");
		return (0);
	}
	if (struct_init(&data, av) == FALSE)
	{
		free_memory(&data, 0);
		return (0);
	}
	if (dinner_create(&data, 0) == FALSE)
	{
		ft_putstr_fd("Error : The dinner didn't go as planned... :(", 2);
		free_memory(&data, 0);
		return (0);
	}
	free_memory(&data, 0);
	return (0);
}
