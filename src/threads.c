/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:48:27 by sade              #+#    #+#             */
/*   Updated: 2024/08/19 10:20:06 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_threads(t_philo *philos, t_data *data, pthread_mutex_t forks[MAX_PHILO])
{
    pthread_t monitor; //thread identifier for monitor thread
    int i;

    if(pthread_create(&monitor, NULL, &monitor_loop, philos) != 0)
        return(destroy_all(philos, forks));
    // printf("** MONITOR STARTED **\n"); /* TEST */
    i = 0;
    //printf("[T_C]Num of philos: %d\n", data->num_philos); /* TEST */
    while(i < data->num_philos)
    {
        if(pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
            return(destroy_all(philos, forks));
        // printf("** CREATED ROUTINE FOR [%d] **\n", philos[i].id); /* TEST */
        i++;
    }
    i = 0;
    if(pthread_join(monitor, NULL) != 0)
        return(destroy_all(philos, forks));
    while(i < data->num_philos)
    {
        if(pthread_join(philos[i].thread, NULL) != 0)
            return(destroy_all(philos, forks));
        i++;
    }
    return(0);
}