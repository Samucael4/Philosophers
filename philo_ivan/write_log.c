/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:16:36 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/26 18:05:02 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_status(t_philo *philo, int status, long elapse)
{
	if (status == EATING)
		printf("%ld %d is eating\n", elapse, philo->id);
	else if (status == HAS_FORK)
		printf("%ld %d has taken a fork\n", elapse, philo->id);
	else if (status == SLEEPING)
		printf("%ld %d is sleeping\n", elapse, philo->id);
	else if (status == THINKING)
		printf("%ld %d is thinking\n", elapse, philo->id);
	else if (status == DEAD)
		printf("%ld %d died\n", elapse, philo->id);
}

void	write_log(t_philo *philo)
{
	long	elapse;
	int		status;

	pthread_mutex_lock(&philo->settings->printf_mutex);
	status = get_int_mtx(&philo->status_mtx, &philo->status);
	elapse = get_current_time() - get_long_mtx(&philo->settings->started_mtx,
			&philo->settings->started);
	if (status != DEAD && check_stop_condition(philo->settings) == 1)
		return (pthread_mutex_unlock(&philo->settings->printf_mutex), (void)0);
	if (status == FULL)
		return (pthread_mutex_unlock(&philo->settings->printf_mutex), (void)0);
	print_status(philo, status, elapse);
	pthread_mutex_unlock(&philo->settings->printf_mutex);
}
