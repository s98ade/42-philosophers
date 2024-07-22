/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:38:44 by sade              #+#    #+#             */
/*   Updated: 2024/07/22 14:00:47 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int takes_forks(t_philo *philo)
{
    //philo takes fork before eating
}

void philo_eats(t_philo *philo)
{
    //philo eats
}

void philo_sleep_think(t_philo *philo)
{
    print_msg("is sleeping", philo, philo->data);
    ft_usleep(philo->time_to_sleep);
    print_msg("is thinking", philo, philo->data);
    
}

void *routine(void *p)
{
    t_philo *philo;

    philo = (t_philo *)p;
    if(philo->id % 2 == 0)
        ft_usleep(1);
    while(!is_deadflag(philo->data))
    {
        philo_eats(philo);
        philo_sleep_think(philo);
    }
    return(p);   
}