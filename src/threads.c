/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:48:27 by sade              #+#    #+#             */
/*   Updated: 2024/07/20 14:36:58 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_threads(t_data *data)
{
    pthread_t *monitor;
    int i;

    if(pthread_create(&monitor, NULL, &monitor_loop, data->philos) != 0)
        //return(destroy_all());
    i = 0;
    while(i < data->num_philos)
    {
        if(pthread_create(&data->philos[i].thread, NULL, &routine, program->ohilos[i]) != 0)
            //return(destroy_all());
        i++;
    }
    i = 0;
    if(pthread_join(monitor, NULL) != 0)
        //return(destroy_all());
    while(i < data->num_philos)
    {
        if(pthread_join(data->philos[i].thread, NULL) != 0)
            //return(destroy_all());
        i++;
    }
    return(0);
}