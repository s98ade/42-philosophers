/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:44:52 by sade              #+#    #+#             */
/*   Updated: 2024/07/29 18:52:31 by sade             ###   ########.fr       */
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
}              t_data;

typedef struct s_philo
{
   int id;
   int times_eaten;
   long time_to_eat;
   long time_to_sleep;
   long time_to_die;
   long start_time;
   long long last_meal;
   pthread_mutex_t eating_lock;
   pthread_mutex_t *r_fork;
   pthread_mutex_t *l_fork;
   pthread_t thread;
   t_data *data; 
}              t_philo;

/* init_data */
void init_data(t_philo *philos, t_data *data, char **argv);
void init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks, char **argv);
void init_forks(pthread_mutex_t *forks, int num_philos);

/* threads */
int create_threads(t_philo *philos, t_data *data);

/* routine */
void *routine(void *p);
int takes_forks(t_philo *philo);
void philo_eats(t_philo *philo);
void philo_sleep_think(t_philo *philo);

/* monitor */
void *monitor_loop(void *ptr);
int is_deadflag(t_philo *philo);
int is_dead(t_philo *philo);
int check_deaths(t_philo *philo);
int ate_max_meals(t_philo *philo);

/* utils1 */
void ft_error(char *msg);
int ft_isnum(char *str);
int ft_isspace(char c);
long	ft_atol(const char *str);
void check_args(char **argv);

/* utils2 */
int ft_strlen(char *str);
long long	get_time(void);
int ft_usleep(size_t ms);
int destroy_all(t_philo *philos);
void print_msg(char *str, t_philo *philo, t_data *data);

#endif