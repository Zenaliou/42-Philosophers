/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:55:33 by niclee            #+#    #+#             */
/*   Updated: 2025/04/02 16:13:32 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
#include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "libft.h"
# include "ft_printf.h"

typedef pthread_mutex_t	t_mxt;

typedef struct s_table	t_table;

typedef struct s_fork
{
	t_mxt		fork;
	int			fork_id;
}				t_fork;

typedef struct s_philo
{
	int				id;
	long			meals_count;
	bool			full;
	long			last_meal_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_t		thread_id;
	t_table			*table;
}			t_philo;

typedef struct s_table
{
	long		philo_nbr;
	long		time_to_die;
	long		time_to_eat;
	long		time_to_sleep;
	long		nbr_limits_meals;
	long		start_simulation;
	bool		end_simulation;
	t_fork		*forks;
	t_philo		*philos;
	pthread_mutex_t	print_mutex;
}				t_table;

t_table	parse(char **av, t_table *table);
int		is_valid_number(char *str);
void	print_error(const char *msg);
void	clean_exit(t_table *table);
void	end_simulation(t_table *table);
bool	start_dinner(t_table *table);
void	destroy(t_table *table);
bool	init(t_table *table);
void	end_simulation(t_table *table);
bool	start_dinner(t_table *table);
void	eat(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);
long	get_time_ms(void);
void	print_status(t_philo *philo, char *status);
void	ft_usleep(long time_in_ms);

#endif