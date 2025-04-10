/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:58:35 by niclee            #+#    #+#             */
/*   Updated: 2025/04/06 15:29:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	destroy_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i].fork);
		i++;
	}
	free(table->forks);
}

void	destroy_philosophers(t_table *table)
{
	free(table->philos);
}

void	destroy(t_table *table)
{
	destroy_forks(table);
	destroy_philosophers(table);
}
