/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:45:02 by sade              #+#    #+#             */
/*   Updated: 2024/07/22 14:03:22 by sade             ###   ########.fr       */
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
    init_data(&philos,&data, argv);
    create_threads(&data);
    destroy_all(&data);
}