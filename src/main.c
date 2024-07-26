/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:02 by sade              #+#    #+#             */
/*   Updated: 2024/07/26 21:49:43 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
    t_philo philos[MAX_PHILO];
    t_data data;

    if(argc < 5)
        ft_error("Argument error\n");
    check_args(argv);
    init_data(philos, &data, argv);
    create_threads(philos, &data);
    destroy_all(philos);
    return (0);
}