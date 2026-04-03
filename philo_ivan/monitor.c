/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:18:20 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/26 17:45:54 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_stop_condition(t_settings *set)
{
	return (get_int_mtx(&set->stop_mtx, &set->stop_simulation));
}

static void	check_philosopher_death(t_philo *philos, t_settings *settings,
		int i)
{
	long	time_since_meal;

	if (check_stop_condition(settings))
		return ;
	if (get_int_mtx(&philos[i].status_mtx, &philos[i].status) == FULL)
		return ;
	time_since_meal = get_current_time()
		- get_long_mtx(&philos[i].last_meal_mtx, &philos[i].last_meal);
	if (time_since_meal >= settings->time_to_die)
	{
		set_int_mtx(&settings->stop_mtx, &settings->stop_simulation, 1);
		set_int_mtx(&philos[i].status_mtx, &philos[i].status, DEAD);
		write_log(&philos[i]);
	}
}

static int	monitor_philosophers(t_philo *philos, t_settings *settings)
{
	int	i;
	int	all_full;

	i = 0;
	all_full = 1;
	while (i < settings->num_philo)
	{
		check_philosopher_death(philos, settings, i);
		if (check_stop_condition(settings))
			return (1);
		if (get_int_mtx(&philos[i].status_mtx, &philos[i].status) != FULL)
			all_full = 0;
		i++;
	}
	if (settings->num_required_meals > 0 && all_full)
	{
		set_int_mtx(&settings->stop_mtx, &settings->stop_simulation, 1);
		return (1);
	}
	return (0);
}

void	*restaurant_manager(void *arg)
{
	t_philo		*philos;
	t_settings	*settings;

	philos = (t_philo *)arg;
	settings = philos[0].settings;
	while (get_int_mtx(&settings->all_threads_mtx,
			&settings->all_threads_created) != 1)
		usleep(100);
	while (!check_stop_condition(settings))
	{
		if (monitor_philosophers(philos, settings))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
