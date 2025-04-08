/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:08:20 by niclee            #+#    #+#             */
/*   Updated: 2025/04/07 18:46:11 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo->table->end_simulation && !philo->full)
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}

bool	start_dinner(t_table *table)
{
	int			i;
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
		return (print_error("Failed to create monitor thread"), false);
	pthread_detach(monitor);
	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread_id, NULL,
				philo_routine, &table->philos[i]) != 0)
			return (print_error("Thread creation failed"), false);
		i++;
	}
	return (true);
}

void	end_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
		pthread_join(table->philos[i++].thread_id, NULL);
	table->end_simulation = true;
}
