/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:37:16 by sade              #+#    #+#             */
/*   Updated: 2024/07/22 13:48:10 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_deadflag(t_data *data)
{
    // loop that continuously checks whether a philo died
    // if so, sets the deat_flag to one
}

int philo_dead(t_philo *philo)
{
    //checks whether a philo died
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
