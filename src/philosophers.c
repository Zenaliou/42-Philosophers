/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:34:39 by marvin            #+#    #+#             */
/*   Updated: 2025/04/06 15:34:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		table = parse(av, &table);
		table.start_simulation = get_time_ms();
		init(&table);
		start_dinner(&table);
		end_simulation(&table);
		destroy(&table);
	}
	else
		print_error("Usage: ./philophers number_philo die eat sleep limits");
	return (EXIT_SUCCESS);
}
