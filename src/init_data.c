/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:28:28 by sade              #+#    #+#             */
/*   Updated: 2024/07/16 20:34:11 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philos(t_philo *philos, t_data *data, char **argv)
{
    int i;

    i = 0;
    while(i < data->num_philos)
    {
        philos[i].id = i + 1;
        philos[i].times_eaten = 0;
        philos[i].start_time = get_time();
        philos[i].last_meal = get_time();
        philos[i].time_to_eat = ft_atol(argv[3]);
        philos[i].time_to_sleep = ft_atol(argv[4]);
        philos[i].time_to_die = ft_atol(argv[2]);
        if(pthread_mutex_init(&philos[i].eating_lock, NULL) != 0)
            ft_error("Error\nMutex\n", NULL, NULL);
        // fork init here
    }
}

void init_data(t_data *data, char **argv)
{
    data->num_philos = ft_atol(argv[1]);
    data->dead_flag = 0;
    if(argv[5])
        data->max_meals = ft_atol(argv[5]);
    else
        data->max_meals = -1;
    if(pthread_mutex_init(&data->dead_lock, NULL) != 0)
        ft_error("Error\nMutex\n", NULL, NULL);    
    if(pthread_mutex_init(&data->write_lock, NULL) != 0)
        ft_error("Error\nMutex\n", NULL, NULL);    
}

