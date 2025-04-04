/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:58:58 by niclee            #+#    #+#             */
/*   Updated: 2025/04/04 19:44:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}


bool	parse_args(char **av, t_table *table)
{
	if (!is_valid_number(av[1]) || !is_valid_number(av[2])
		|| !is_valid_number(av[3]) || (av[5] && !is_valid_number(av[5])))
		return (print_error("Invalid argument values."), false);
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		table->nbr_limits_meals = ft_atol(av[5]);
	else
		table->nbr_limits_meals = -1;
	if (table->philo_nbr <= 0 || table->time_to_die <= 0
		|| table->time_to_eat <= 0 || table->time_to_sleep <= 0)
		return (print_error("Arguments must be positive values."), false);
	if (av[5] && table->nbr_limits_meals <= 0)
	{
		print_error("Meals count must be greater than 0.");
		return (false);
	}
	return (true);
}

t_table	parse(char **av, t_table *table)
{
	if (!parse_args(av, table))
		exit(EXIT_FAILURE);
	table->end_simulation = false;
	table->start_simulation = 0;
	return (*table);
}
