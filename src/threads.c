/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 09:48:27 by sade              #+#    #+#             */
/*   Updated: 2024/07/22 10:59:08 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int create_threads(t_data *data)
{
    pthread_t *monitor;
    int i;

    if(pthread_create(&monitor, NULL, &monitor_loop, data->philos) != 0)
        return(destroy_all(data));
    i = 0;
    while(i < data->num_philos)
    {
        if(pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]) != 0)
            return(destroy_all(data));
        i++;
    }
    i = 0;
    if(pthread_join(monitor, NULL) != 0)
        return(destroy_all(data));
    while(i < data->num_philos)
    {
        if(pthread_join(data->philos[i].thread, NULL) != 0)
            return(destroy_all(data));
        i++;
    }
    return(0);
}