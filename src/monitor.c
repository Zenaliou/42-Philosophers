/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:27:50 by niclee            #+#    #+#             */
/*   Updated: 2025/04/04 19:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (!table->end_simulation)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			pthread_mutex_lock(&table->print_mutex);
			if ((get_time_ms() - table->philos[i].last_meal_time) > table->time_to_die)
			{
				table->end_simulation = true;
				printf("%ld %d died\n", get_time_ms() - table->start_simulation, table->philos[i].id);
				pthread_mutex_unlock(&table->print_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&table->print_mutex);
			i++;
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
	if (table->nbr_limits_meals > 0
		&& count_full_philos(table) == table->philo_nbr)
	{
		table->end_simulation = true;
		return (0);
	}	
	return (count);
}