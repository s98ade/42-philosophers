/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:37:16 by sade              #+#    #+#             */
/*   Updated: 2024/08/19 10:19:15 by sade             ###   ########.fr       */
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
       // printf("<- leaving is_deadflag() with philo: %d, DEAD_FLAG: %d\n", philo->id, philo->data->dead_flag);
        return (1);
    }
    pthread_mutex_unlock(&philo->data->dead_lock);
    //printf("<- leaving is_deadflag() with philo: %d, DEAD_FLAG: %d\n", philo->id, philo->data->dead_flag);
    return (0);
}

int is_dead(t_philo *philo)
{
    // printf("-> entering --is_dead()-- with philo: %d\n", philo->id); /* TEST */
    pthread_mutex_lock(&philo->eating_lock);
    long long current_time = get_time();
    //printf("INFO PHILO [%d]: current_time: %lld, time_to_die: %ld\n", philo->id, current_time, philo->time_to_die);
    // printf("current_time - last_meal = [%lld]\n", current_time - philo->last_meal);
    if(current_time - philo->last_meal >= philo->time_to_die)
    {
        print_msg("died 💀", philo, philo->data);
        pthread_mutex_unlock(&philo->eating_lock);
        // printf("<- leaving is_dead() with philo [%d]\n", philo->id);
        return (1);
    }
    pthread_mutex_unlock(&philo->eating_lock);
    // printf("<- leaving is_dead() with philo [%d]\n", philo->id);
    return (0);
}

int check_deaths(t_philo *philo)
{
    int i;

    i = 0;
    //printf("-> entering --check_deaths()-- with philo: %d\n", philo->id); /* TEST */
   // printf("[C_D]Num of philos: %d\n", philo->data->num_philos); /* TEST */
    while(i < philo->data->num_philos)
    {
        if(is_dead(&philo[i]))
        {
            pthread_mutex_lock(&philo->data->dead_lock);
            philo->data->dead_flag = 1;
            // printf("DEADFLAG: [%d]\n", philo->data->dead_flag);
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
    //printf("INFO philo [%d]: times_eaten = [%d], max_meals = [%d]\n", philo->id, philo->times_eaten, philo->data->max_meals);
    if(philo->data->max_meals == -1)
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
    pthread_mutex_lock(&philo->data->dead_lock);
    philo->data->dead_flag = 1;
    pthread_mutex_unlock(&philo->data->dead_lock);
    return(1);
}

void *monitor_loop(void *ptr)
{
    t_philo *philos;
    
    philos = (t_philo *)ptr;
    while(1)
    {
        //printf("* Monitor running *\n"); /* TEST */
        if(ate_max_meals(philos) == 1 || check_deaths(philos) == 1)
            break ;
        //ft_usleep(100);
    }
    return(ptr);    
}
