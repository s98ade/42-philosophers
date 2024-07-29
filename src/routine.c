/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:38:44 by sade              #+#    #+#             */
/*   Updated: 2024/07/29 16:21:51 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int takes_forks(t_philo *philo)
{
    //printf("-> entering --takes_forks()-- with philo: %d\n", philo->id); /* TEST */
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
   // printf("-> entering --philo_eats()-- with philo: %d\n", philo->id); /* TEST */
    if(takes_forks(philo) == 1)
        return ; 
    print_msg("is eating 🍝", philo, philo->data);
    pthread_mutex_lock(&philo->eating_lock);
    philo->last_meal = get_time();
    ++philo->times_eaten;
    pthread_mutex_unlock(&philo->eating_lock);
    ft_usleep(philo->time_to_eat);
    pthread_mutex_unlock(philo->l_fork);
    pthread_mutex_unlock(philo->r_fork);
}

void philo_sleep_think(t_philo *philo)
{
    //printf("-> entering --philo_sleep_think()-- with philo: %d\n", philo->id); /* TEST */
    print_msg("is sleeping 😴", philo, philo->data);
    ft_usleep(philo->time_to_sleep);
    print_msg("is thinking 🤔", philo, philo->data);
}

void *routine(void *p)
{
    t_philo *philo;

    philo = (t_philo *)p;
   // printf("* start routine for philo %d *\n", philo->id);
    if(philo->id % 2 == 0)
        ft_usleep(1);
    while(!is_deadflag(philo))
    {
       // printf("dead_flag: %d\n", philo->data->dead_flag);
        philo_eats(philo);
        philo_sleep_think(philo);
    }
    return(p);   
}

/* void *routine(void *p) // test function
{
    t_philo *philo;

    printf("Starting routine\n");
    philo = (t_philo *)p;
    if (philo == NULL) {
        printf("philo is NULL\n");
        return NULL;
    }

    printf("Philo ID: %d\n", philo->id);
    printf("Shared data at: %p\n", (void *)philo->data);
    printf("Philos data at: %p\n", (void *)philo);
    if (philo->data != NULL) {
        printf("Num Philos: %d\n", philo->data->num_philos);
    } else {
        printf("philo->data is NULL\n");
    }

    if (philo->id % 2 == 0)
        ft_usleep(1);

    while (!is_deadflag(philo))
    {
        philo_eats(philo);
        philo_sleep_think(philo);
    }
    return p;
} */