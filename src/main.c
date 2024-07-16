/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:02 by sade              #+#    #+#             */
/*   Updated: 2024/07/16 13:25:12 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_data data;
    t_philo philos[MAX_PHILO];

    if(argc != 5 || argc != 6)
        ft_error("Argument error\n", NULL, NULL);
    check_args(argv);
    //init_data();
}