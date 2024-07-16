/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:08:07 by sade              #+#    #+#             */
/*   Updated: 2024/07/16 11:36:58 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isnum(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return(1);
        i++;
    }
    return(0);
}

int ft_isspace(char c)
{
    if(c == '\n' || c == '\r' || c == '\v'
	|| c == ' ' || c == '\f' || c == '\t')
            return(1);
    return(0);
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			error_exit("Error: Negative input\n", 1, NULL);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != 0)
		error_exit("Error: Non numeric input", 1, NULL);
	if (nbr > INT_MAX)
		error_exit("Error: Input bigger than INT_MAX\n", 1, NULL);
	return (nbr);
}

void check_args(char **argv)
{
    if(ft_atol(argv[1]) > MAX_PHILO || ft_atol(argv[1] <= 0) || ft_isnum(argv[1]) == 1)
        ft_error();
    if(ft_atol(argv[2]) >= 0 || ft_isnum(argv[2]) == 1)
        ft_error();
    if(ft_atol(argv[3] <= 0) || ft_isnum(argv[3]) == 1)
        ft_error();
    if(ft_atol(argv[4] <= 0) || ft_isnum(argv[4]) == 1)
        ft_error();
    if(argv[5] && (argv[5] < 0 || ft_isnum(argv[5]) == 1))
        ft_error();
}