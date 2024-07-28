/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 18:28:28 by sade              #+#    #+#             */
/*   Updated: 2024/07/28 14:47:52 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philos(t_philo *philos, t_data *data, char **argv)
{
    pthread_mutex_t forks[MAX_PHILO];
    int i;

    i = -1;
    while(++i < data->num_philos)
    {
        philos[i].id = i + 1;
        philos[i].times_eaten = 0;
        philos[i].start_time = get_time();
        philos[i].last_meal = get_time();
        philos[i].time_to_eat = ft_atol(argv[3]);
        philos[i].time_to_sleep = ft_atol(argv[4]);
        philos[i].time_to_die = ft_atol(argv[2]);
        philos[i].data = data; //setting data pointer for each philo
        if(pthread_mutex_init(&philos[i].eating_lock, NULL) != 0)
            ft_error("Error\nMutex\n");
        if(argv[5])
            data->max_meals = ft_atol(argv[5]);
        else
            data->max_meals = -1;
        init_forks(philos, forks, data->num_philos);
    }
}

void init_forks(t_philo *philos, pthread_mutex_t *forks, int num_philos)
{
    int i;

    i = 0;
    while (i < num_philos)
    {
        philos[i].r_fork = &forks[i];
        if (pthread_mutex_init(philos[i].r_fork, NULL) != 0)
            ft_error("Error: Mutex\n");
        i++;
    }

    i = 0;
    while (i < num_philos)
    {
        if (i == 0 && num_philos != 1)
            philos[i].l_fork = philos[num_philos - 1].r_fork;
        else if (num_philos != 1)
            philos[i].l_fork = philos[i - 1].r_fork;
        else
            philos[i].l_fork = NULL; 
        i++;  
    }
}

void init_data(t_philo *philos, t_data *data, char **argv)
{
    data->num_philos = ft_atol(argv[1]);
    data->dead_flag = 0;
    if(argv[5])
        data->max_meals = ft_atol(argv[5]);
    else
        data->max_meals = -1;
    if(pthread_mutex_init(&data->dead_lock, NULL) != 0)
        ft_error("Error\nMutex: dead_lock\n");    
    if(pthread_mutex_init(&data->write_lock, NULL) != 0)
        ft_error("Error\nMutex: write_lock\n");
    init_philos(philos, data, argv);   
}
