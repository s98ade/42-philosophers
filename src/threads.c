/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:48:27 by sade              #+#    #+#             */
/*   Updated: 2024/07/26 22:05:17 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_threads(t_philo *philos, t_data *data)
{
    pthread_t monitor; //???
    int i;

    if(pthread_create(&monitor, NULL, &monitor_loop, philos) != 0)
        return(destroy_all(philos));
    i = 0;
    printf("Num of philos: %d\n", data->num_philos);
    while(i < data->num_philos)
    {
        if(pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
            return(destroy_all(philos));
        printf("created thread for %d\n", philos->id);
        i++;
    }
    i = 0;
    if(pthread_join(monitor, NULL) != 0)
        return(destroy_all(philos));
    while(i < data->num_philos)
    {
        if(pthread_join(philos[i].thread, NULL) != 0)
            return(destroy_all(philos));
        i++;
    }
    return(0);
}