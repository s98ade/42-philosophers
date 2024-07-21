/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:44:52 by sade              #+#    #+#             */
/*   Updated: 2024/07/21 13:29:38 by sade             ###   ########.fr       */
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
    int max_meals;
    pthread_mutex_t dead_lock;
    pthread_mutex_t write_lock;
    t_philo *philos;
}              t_data;

typedef struct s_philo
{
   int id;
   int times_eaten;
   size_t time_to_eat;
   size_t time_to_sleep;
   size_t time_to_die;
   size_t start_time;
   size_t last_meal;
   pthread_mutex_t *eating_lock;
   pthread_mutex_t *r_fork;
   pthread_mutex_t *l_fork;
   pthread_t thread;
   t_data *data; 
}              t_philo;

/* init_data */
void init_data(t_philo *philos, t_data *data, char **argv);
void init_philos(t_philo *philos, t_data *data, char **argv);
void init_forks(t_philo *philos, int num_philos, int i);

/* threads */
int create_threads(t_data *data);

/* routine */
void *routine(void *p);

/* monitor */
void *monitor_loop();
int philo_dead(t_philo *philo);


/* utils1 */
void ft_error(char *msg, t_data *data, int flag);
int ft_isnum(char *str);
int ft_isspace(char c);
long	ft_atol(const char *str);
void check_args(char **argv);

/* utils2 */
int ft_strlen(char *str);
size_t	get_time(void);
void ft_usleep(size_t ms);

#endif