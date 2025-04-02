/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:55:04 by niclee            #+#    #+#             */
/*   Updated: 2025/04/02 16:01:29 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(sizeof(t_fork) * table->philo_nbr);
	if (!table->forks)
		return (print_error("Mutex init failed"), false);
	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
			return (print_error("Mutex init failed"), false);
		i++;
	}
	return (true);
}

static bool	init_philosophers(t_table *table)
{
	int	i;

	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philos)
		return (print_error("Mutex init failed"), false);
	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_count = 0;
		table->philos[i].full = false;
		table->philos[i].last_meal_time = 0;
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
		table->philos[i].table = table;
		i++;
	}
	return (true);
}

bool	init(t_table *table)
{
	if (!init_forks(table) || !init_philosophers(table))
		return (clean_exit(table), false);
	return (true);
}
