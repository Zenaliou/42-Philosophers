/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niclee <niclee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:49:35 by niclee            #+#    #+#             */
/*   Updated: 2025/04/02 16:12:55 by niclee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork->fork);
    print_status(philo, "has taken a fork");
    pthread_mutex_lock(&philo->right_fork->fork);
    print_status(philo, "has taken a fork");

    print_status(philo, "is eating");
    philo->last_meal_time = get_time_ms();
    philo->meals_count++;
    ft_usleep(philo->table->time_to_eat);
    pthread_mutex_unlock(&philo->left_fork->fork);
    pthread_mutex_unlock(&philo->right_fork->fork);
}

void sleep_philo(t_philo *philo)
{
    print_status(philo, "is sleeping");
    ft_usleep(philo->table->time_to_sleep);
}

void think(t_philo *philo)
{
    print_status(philo, "is thinking");
}