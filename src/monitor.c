/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:27:50 by niclee            #+#    #+#             */
/*   Updated: 2025/04/08 20:22:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static bool	check_philo_death(t_table *table, int i)
{
	long	time_diff;
	long	ts;

	time_diff = get_time_ms() - table->philos[i].last_meal_time;
	if (time_diff > table->time_to_die)
	{
		ts = get_time_ms() - table->start_simulation;
		table->end_simulation = true;
		pthread_mutex_lock(&table->print_mutex);
		printf("\033[0;31m%ld %d died\033[0m\n", ts, table->philos[i].id);
		pthread_mutex_unlock(&table->print_mutex);
		return (true);
	}
	return (false);
}

static bool	check_meal_limits(t_table *table)
{
	if (table->nbr_limits_meals > 0
		&& count_full_philos(table) == table->philo_nbr)
	{
		table->end_simulation = true;
		return (true);
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (!table->end_simulation)
	{
		i = 0;
		while (i < table->philo_nbr && !table->end_simulation)
		{
			if (check_philo_death(table, i))
				return (NULL);
			i++;
		}
		if (check_meal_limits(table))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	count_full_philos(t_table *table)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (i < table->philo_nbr)
	{
		if (table->philos[i].full)
			count++;
		i++;
	}
	return (count);
}
