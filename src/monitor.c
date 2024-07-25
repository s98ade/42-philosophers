/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:37:16 by sade              #+#    #+#             */
/*   Updated: 2024/07/25 19:08:57 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_deadflag(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    pthread_mutex_unlock(&data->dead_lock);
}

int is_dead(t_philo *philo)
{
    pthread_mutex_lock(philo->eating_lock);
    if(get_time() - philo->last_meal >= philo->time_to_die)
    {
        pthread_mutex_unlock(philo->eating_lock);
        return (1);
    }
    pthread_mutex_unlock(philo->eating_lock);
    return (0);
}

int check_deaths(t_philo *philos)
{
    //checks if any philosopher died
}

int ate_max_meals(t_philo *philos)
{
    //checks whether all philos ate max_meals
}

void *monitor_loop(void *ptr)
{
    t_philo *philos;
    
    philos = (t_philo *)ptr;
    while(1)
        if(ate_max_meals(philos) == 1 || check_deaths(philos) == 1)
            break ;
    return(ptr);    
}
