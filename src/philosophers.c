/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:51:49 by niclee            #+#    #+#             */
/*   Updated: 2025/04/02 15:54:25 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int    main(int ac, char **av)
{
    t_table    table;

    if (ac == 5 || ac == 6)
    {
        table = parse(av, &table);
        if (!init(&table))
            return (EXIT_FAILURE);
        if (!start_dinner(&table))
            return (destroy(&table), EXIT_FAILURE);
        end_simulation(&table);
        destroy(&table);
    }
    else
        print_error("Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_meals]");
    return (EXIT_SUCCESS);
}
