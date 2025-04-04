/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:51:49 by niclee            #+#    #+#             */
/*   Updated: 2025/04/04 19:56:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int    main(int ac, char **av)
{
    t_table    table;

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
        print_error("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_meals]");
    return (EXIT_SUCCESS);
}
