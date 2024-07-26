/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:48:27 by sade              #+#    #+#             */
/*   Updated: 2024/07/26 18:33:23 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_threads(t_philo *philos)
{
    pthread_t monitor; //???
    int i;

    if(pthread_create(&monitor, NULL, &monitor_loop, philos) != 0)
        return(destroy_all(philos));
    i = 0;
    while(i < philos->data->num_philos)
    {
        if(pthread_create(&philos[i].thread, NULL, &routine, &philos[i]) != 0)
            return(destroy_all(philos));
        i++;
    }
    i = 0;
    if(pthread_join(monitor, NULL) != 0)
        return(destroy_all(philos));
    while(i < philos->data->num_philos)
    {
        if(pthread_join(philos[i].thread, NULL) != 0)
            return(destroy_all(philos));
        i++;
    }
    return(0);
}