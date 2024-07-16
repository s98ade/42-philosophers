/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:44:52 by sade              #+#    #+#             */
/*   Updated: 2024/07/16 13:20:49 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<limits.h>
#include<sys/time.h>

# define MAX_PHILO 200

typedef struct s_data
{
    int num_philos;
    int dead_flag;
    t_philo *philos;
}              t_data;

typedef struct s_philo
{
   int id;
   int meals_eaten;
   size_t time_to_eat;
   size_t time_to_sleep;
   size_t time_to_die;
   size_t start_time;
   pthread_t thread;
   t_data *data; 
}              t_philo;

/* utils1 */
void ft_error(char *msg, t_data *data, int flag);
int ft_isnum(char *str);
int ft_isspace(char c);
long	ft_atol(const char *str);
void check_args(char **argv);

/* utils2 */
int ft_strlen(char *str);

#endif