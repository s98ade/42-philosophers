/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:33:25 by sade              #+#    #+#             */
/*   Updated: 2024/07/26 09:12:12 by sade             ###   ########.fr       */
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

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error\nGetting time failed\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}


// busy-wait loop -> not very CPU efficient, consumes a lot of processor power
void ft_usleep(size_t ms)
{
    size_t start;

    start = get_time();
    while((get_time() - start) < ms)
        usleep(500); 
}

int destroy_all(t_data *data)
{
    int i;

    i = 0;
    while(i < data->num_philos)
    {
        pthread_mutex_destroy(data->philos[i].l_fork);
        pthread_mutex_destroy(data->philos[i].r_fork);
    }
    pthread_mutex_destroy(&data->dead_lock);
    pthread_mutex_destroy(&data->philos->eating_lock);
    pthread_mutex_destroy(&data->write_lock);
    return(1);
}

void print_msg(char *str, t_philo *philo, t_data *data)
{
    size_t time;

    pthread_mutex_lock(&data->write_lock);
    time = get_time() - philo->start_time;
    if(!check_death(philo))
        printf("%zu %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&data->write_lock);
}