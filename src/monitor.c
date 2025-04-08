/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:27:50 by niclee            #+#    #+#             */
/*   Updated: 2025/04/08 17:48:57 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_table	*table = (t_table *)arg;
	int		i;
	long	time_diff;
	long	timestamp;

	while (!table->end_simulation)
	{
		i = 0;
		while (i < table->philo_nbr && !table->end_simulation)
		{
			time_diff = get_time_ms() - table->philos[i].last_meal_time;
			if (time_diff > table->time_to_die)
			{
				timestamp = get_time_ms() - table->start_simulation;
				table->end_simulation = true;
				pthread_mutex_lock(&table->print_mutex);
				printf("\033[0;31m%ld %d died\033[0m\n", timestamp, table->philos[i].id);
				pthread_mutex_unlock(&table->print_mutex);
				return (NULL);
			}
			i++;
		}
		if (table->nbr_limits_meals > 0 && count_full_philos(table) == table->philo_nbr)
        {
            table->end_simulation = true;
            return (NULL);
        }
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
	// if (table->nbr_limits_meals > 0
	// 	&& count_full_philos(table) == table->philo_nbr)
	// {
	// 	table->end_simulation = true;
	// 	return (0);
	// }
	return (count);
}
