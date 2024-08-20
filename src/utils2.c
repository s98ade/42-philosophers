/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:33:25 by sade              #+#    #+#             */
/*   Updated: 2024/08/20 21:31:58 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error\nGetting time failed\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int ft_usleep(size_t ms)
{
    size_t start;

    start = get_time();
    while((get_time() - start) < ms)
        usleep(100);
    return(0); 
}

int destroy_all(t_philo *philos, pthread_mutex_t forks[MAX_PHILO])
{
    int i;

    i = 0;
    while(i++ < philos->data->num_philos)
    {
        pthread_mutex_destroy(&(forks[i]));
        pthread_mutex_destroy(&philos->eating_lock);
    }
    pthread_mutex_destroy(&philos->data->dead_lock);
    pthread_mutex_destroy(&philos->data->write_lock);
    return(1);
}

void print_msg(char *str, t_philo *philo, t_data *data)
{
    long long time;
    
    pthread_mutex_lock(&data->write_lock);
    pthread_mutex_lock(&philo->data->dead_lock);
    time = get_time() - philo->start_time;
    if (!philo->data->dead_flag)
        printf("%lld %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&data->write_lock);
    pthread_mutex_unlock(&philo->data->dead_lock);
}