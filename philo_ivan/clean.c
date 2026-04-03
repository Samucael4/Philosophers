/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:17:42 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/19 15:19:57 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean(t_settings *settings, t_philo *philos, t_fork *forks)
{
	int	i;

	i = 0;
	while (i < settings->num_philo)
	{
		pthread_mutex_destroy(&philos[i].status_mtx);
		pthread_mutex_destroy(&philos[i].meals_eaten_mtx);
		pthread_mutex_destroy(&philos[i].last_meal_mtx);
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&settings->stop_mtx);
	pthread_mutex_destroy(&settings->printf_mutex);
	pthread_mutex_destroy(&settings->started_mtx);
	free(philos);
	free(forks);
}
