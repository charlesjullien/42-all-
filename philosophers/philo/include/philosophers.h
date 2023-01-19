/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjullien <cjullien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:24:37 by cjullien          #+#    #+#             */
/*   Updated: 2021/11/16 14:44:56 by cjullien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define FALSE 0
# define TRUE 1
# define INT_MAX 2147483647

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_curr_philosopher	t_curr_philosopher;
struct								s_curr_philosopher
{
	int				index;
	int				left_fork;
	int				right_fork;
	int				meals;
	long long		recent_meal;
	struct s_data	*d;
	pthread_t		thread_index;
};

typedef struct s_data				t_data;
struct								s_data
{
	int					nb_ph;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_must_eat;
	int					all_fed;
	int					dead;
	long long			starter_time;
	t_curr_philosopher	*curr_philo;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printer;
	pthread_mutex_t		e;
	pthread_mutex_t		c;
	pthread_mutex_t		b;
	pthread_mutex_t		a;
};

int			struct_init(t_data *d, char **av);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
int			dinner_create(t_data *d, int i);
long long	get_time_milisec(void);
void		print_activity(t_data *d, char *str, int id);
void		philo_dodo(t_data *d, long long locked_time);
void		free_memory(t_data *d, int i);
long long	lock_time(t_data *d);
void		dinner_starter_2(t_data *d, int i);
void		death_checker_2(t_curr_philosopher *cp, t_data *d, int i);

#endif
