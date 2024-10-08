/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:28:28 by sade              #+#    #+#             */
/*   Updated: 2024/08/21 09:27:51 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		philos[i].id = i + 1;
		philos[i].times_eaten = 0;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		philos[i].time_to_eat = ft_atol(argv[3]);
		philos[i].time_to_sleep = ft_atol(argv[4]);
		philos[i].time_to_die = ft_atol(argv[2]);
		philos[i].data = data;
		if (pthread_mutex_init(&philos[i].eating_lock, NULL) != 0)
			ft_error("Error\nMutex\n");
		philos[i].l_fork = &forks[i];
		philos[i].r_fork = &forks[(i + 1) % data->num_philos];
		i++;
	}
}

void	init_forks(pthread_mutex_t forks[MAX_PHILO], int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
}

void	init_data(t_philo *philos, pthread_mutex_t forks[MAX_PHILO],
		t_data *data, char **argv)
{
	data->num_philos = ft_atol(argv[1]);
	data->dead_flag = 0;
	if (argv[5])
		data->max_meals = ft_atol(argv[5]);
	else
		data->max_meals = -1;
	if (pthread_mutex_init(&data->dead_lock, NULL) != 0)
		ft_error("Error\nMutex: dead_lock\n");
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		ft_error("Error\nMutex: write_lock\n");
	init_forks(forks, data->num_philos);
	init_philos(philos, data, forks, argv);
}
