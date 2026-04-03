/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sim_philos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:27:55 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/22 01:00:47 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	single_philo(t_philo *p)
{
	set_int_mtx(&p->status_mtx, &p->status, HAS_FORK);
	write_log(p);
	better_usleep(p->settings->time_to_die, p->settings);
	set_int_mtx(&p->status_mtx, &p->status, DEAD);
	write_log(p);
}

void	*start_philo(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	while (p->settings->all_threads_created != 1)
		usleep(100);
	set_long_mtx(&p->last_meal_mtx, &p->last_meal,
		get_long_mtx(&p->settings->started_mtx, &p->settings->started));
	if (p->settings->num_philo == 1)
		return (single_philo(p), arg);
	if (p->id % 2 == 0)
		usleep(1000);
	while (!check_stop_condition(p->settings) && get_int_mtx(&p->status_mtx,
			&p->status) != FULL)
	{
		eating(p);
		if (get_int_mtx(&p->status_mtx, &p->status) == FULL)
			break ;
		sleeping(p);
		thinking(p);
	}
	return (arg);
}

static int	create_philosopher_threads(t_settings *settings, t_philo *philos)
{
	int	i;
	int	res;

	i = 0;
	while (i < settings->num_philo)
	{
		res = pthread_create(&philos[i].thread, NULL, start_philo,
				(void *)&(philos[i]));
		if (res != 0)
			return (-1);
		i++;
	}
	return (0);
}

static void	join_all_threads(t_settings *settings, t_philo *philos,
		pthread_t restaurant)
{
	int	i;

	i = 0;
	while (i < settings->num_philo)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(restaurant, NULL);
}

int	start_simulation(t_settings *settings, t_philo *philos)
{
	pthread_t	restaurant;

	if (settings->num_required_meals == 0)
		return (0);
	if (settings->num_philo == 1)
	{
		if (pthread_create(&philos[0].thread, NULL, start_philo,
				&philos[0]) != 0)
			return (-1);
	}
	else
	{
		if (create_philosopher_threads(settings, philos) != 0)
			return (-1);
		if (pthread_create(&restaurant, NULL, restaurant_manager, philos) != 0)
			return (-1);
	}
	set_long_mtx(&settings->started_mtx, &settings->started,
		get_current_time());
	set_int_mtx(&settings->all_threads_mtx, &settings->all_threads_created, 1);
	if (settings->num_philo == 1)
		pthread_join(philos[0].thread, NULL);
	else
		join_all_threads(settings, philos, restaurant);
	return (0);
}
