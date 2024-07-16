/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:44:52 by sade              #+#    #+#             */
/*   Updated: 2024/07/16 11:39:14 by sade             ###   ########.fr       */
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
    
}              t_data;

typedef struct s_philo
{
   t_data *data; 
}              t_philo;

/* utils1 */
int ft_isnum(char *str);
int ft_isspace(char c);
long	ft_atol(const char *str);
void check_args(char **argv);

#endif