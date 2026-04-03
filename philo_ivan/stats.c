/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:16:54 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/21 23:56:00 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->left_hand->mutex);
	set_int_mtx(&philo->status_mtx, &philo->status, HAS_FORK);
	write_log(philo);
	pthread_mutex_lock(&philo->right_hand->mutex);
	set_int_mtx(&philo->status_mtx, &philo->status, HAS_FORK);
	write_log(philo);
	set_int_mtx(&philo->status_mtx, &philo->status, EATING);
	set_long_mtx(&philo->last_meal_mtx, &philo->last_meal, get_current_time());
	write_log(philo);
	better_usleep(philo->settings->time_to_eat, philo->settings);
	meals = get_int_mtx(&philo->meals_eaten_mtx, &philo->meals_eaten) + 1;
	set_int_mtx(&philo->meals_eaten_mtx, &philo->meals_eaten, meals);
	if (philo->settings->num_required_meals > 0
		&& meals >= philo->settings->num_required_meals)
		set_int_mtx(&philo->status_mtx, &philo->status, FULL);
	pthread_mutex_unlock(&philo->right_hand->mutex);
	pthread_mutex_unlock(&philo->left_hand->mutex);
}

void	sleeping(t_philo *philo)
{
	set_int_mtx(&philo->status_mtx, &philo->status, SLEEPING);
	write_log(philo);
	better_usleep(philo->settings->time_to_sleep, philo->settings);
}

void	thinking(t_philo *p)
{
	long	think_time;

	set_int_mtx(&p->status_mtx, &p->status, THINKING);
	write_log(p);
	if (p->settings->num_philo % 2 != 0)
	{
		think_time = p->settings->time_to_eat * 2 - p->settings->time_to_sleep;
		if (think_time < 0)
			think_time = 0;
		better_usleep(think_time, p->settings);
	}
}
