/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:21:26 by niclee            #+#    #+#             */
/*   Updated: 2025/04/02 00:09:30 by marvin           ###   ########.fr       */
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
