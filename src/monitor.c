/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:37:16 by sade              #+#    #+#             */
/*   Updated: 2024/07/28 14:54:41 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int is_deadflag(t_philo *philo)
{
    //printf("-> entering --is_deadflag()-- with philo: %d\n", philo->id); /* TEST */
    pthread_mutex_lock(&philo->data->dead_lock);
    if(philo->data->dead_flag == 1)
    {
        pthread_mutex_unlock(&philo->data->dead_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->dead_lock);
    return (0);
}

int is_dead(t_philo *philo)
{
    //printf("-> entering --is_dead()-- with philo: %d\n", philo->id); /* TEST */
    pthread_mutex_lock(&philo->eating_lock);
    if((get_time() - philo->last_meal) >= philo->time_to_die)
    {
        print_msg("died 💀", philo, philo->data);
        pthread_mutex_unlock(&philo->eating_lock);
        return (1);
    }
    pthread_mutex_unlock(&philo->eating_lock);
    return (0);
}

int check_deaths(t_philo *philo)
{
    int i;

    i = 0;
    //printf("-> entering --check_deaths()-- with philo: %d\n", philo->id); /* TEST */
    //printf("[C_D]Num of philos: %d\n", philo->data->num_philos); /* TEST */
    while(i < philo->data->num_philos)
    {
        if(is_dead(&philo[i]))
        {
            pthread_mutex_lock(&philo->data->dead_lock);
            philo->data->dead_flag = 1;
            pthread_mutex_unlock(&philo->data->dead_lock);
            return(1);
        }
        i++;
    }
    return(0);
}

int ate_max_meals(t_philo *philo)
{
    int i;

    i = 0;
    //printf("[A_M_M]times_eaten of philo [%d]: %d\n", philo->id, philo->times_eaten); /* TEST */
    //printf("-> entering --ate_max_meals()-- with philo: %d\n", philo->id); /* TEST */
    if(philo->times_eaten == -1)
        return(0);
    while(i < philo->data->num_philos)
    {
        pthread_mutex_lock(&philo[i].eating_lock);
        if(philo[i].times_eaten < philo->data->max_meals)
        {
            pthread_mutex_unlock(&philo[i].eating_lock);
            return(0);
        }
        pthread_mutex_unlock(&philo[i].eating_lock);
        i++;
    }
    is_deadflag(philo);
    return(1);
}

void *monitor_loop(void *ptr)
{
    t_philo *philos;
    
    philos = (t_philo *)ptr;
    while(1)
    {
       // printf("* Monitor running *\n"); /* TEST */
        if(ate_max_meals(philos) == 1 || check_deaths(philos) == 1)
            break ;
    }
    return(ptr);    
}
