/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:21:26 by niclee            #+#    #+#             */
/*   Updated: 2025/04/09 15:53:17 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
	printf("Error: %s\n", msg);
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
	long	timestamp;

	if (!philo || !philo->table || !status)
		return ;
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->end_simulation)
	{
		timestamp = get_time_ms() - philo->table->start_simulation;
		if (ft_strncmp(status, "is eating", 9) == 0)
			printf("\033[0;32m");
		else if (ft_strncmp(status, "is sleeping", 11) == 0)
			printf("\033[0;34m");
		else if (ft_strncmp(status, "is thinking", 11) == 0)
			printf("\033[0;33m");
		else if (ft_strncmp(status, "has taken a fork", 16) == 0)
			printf("\033[0;35m");
		else if (ft_strncmp(status, "died", 4) == 0)
			printf("\033[0;31m");
		printf("%ld %d %s\n", timestamp, philo->id, status);
		printf("\033[0m");
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}
