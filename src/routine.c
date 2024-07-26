/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:38:44 by sade              #+#    #+#             */
/*   Updated: 2024/07/26 09:45:28 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int takes_forks(t_philo *philo)
{
    pthread_mutex_lock(philo->r_fork);
    print_msg("has taken a fork 🍽️", philo, philo->data);
    if(philo->data->num_philos == 1)
    {
        pthread_mutex_unlock(philo->r_fork);
        return (1);
    }
    pthread_mutex_lock(philo->l_fork);
    print_msg("has taken a fork 🍽️", philo, philo->data);
    return (0);
}

void philo_eats(t_philo *philo)
{
    if(takes_forks(philo) == 1);
        return ; 
    print_msg("is eating 🍝", philo, philo->data);
    pthread_mutex_lock(philo->eating_lock);
    philo->last_meal = get_time();
    ++philo->times_eaten;
    pthread_mutex_unlock(philo->eating_lock);
    ft_usleep(philo->time_to_eat);
    pthread_mutex_unlock(philo->r_fork);
    pthread_mutex_unlock(philo->l_fork);
}

void philo_sleep_think(t_philo *philo)
{
    print_msg("is sleeping 😴", philo, philo->data);
    ft_usleep(philo->time_to_sleep);
    print_msg("is thinking 🤔", philo, philo->data);
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