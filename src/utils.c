/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:21:26 by niclee            #+#    #+#             */
/*   Updated: 2025/04/02 16:11:41 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	is_valid_number(char *str)
{
	int		i;
	long	num;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

void	print_error(const char *msg)
{
	ft_printf("Error: %s\n", msg);
}

void	clean_exit(t_table *table)
{
	if (table->forks)
		free(table->forks);
	if (table->philos)
		free(table->philos);
}

void	print_status(t_philo *philo, char *status)
{
	long    timestamp;

    pthread_mutex_lock(&philo->table->print_mutex);
    if (!philo->table->end_simulation)
    {
        timestamp = get_time_ms() - philo->table->start_simulation;
        printf("%ld %d %s\n", timestamp, philo->id, status);
    }
    pthread_mutex_unlock(&philo->table->print_mutex);
}