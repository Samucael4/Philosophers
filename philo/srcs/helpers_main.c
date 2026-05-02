/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 20:15:04 by smarques          #+#    #+#             */
/*   Updated: 2026/05/02 20:15:45 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	wraper_threads_join(t_lyceum *l, t_featherless_biped *p)
{
	l->i = 0;
	while (l->i < l->nbr_philos)
	{
		pthread_join(p[l->i].thread_philo, NULL);
		l->i++;
	}
}

bool	end_simulation_verification(t_lyceum *l, t_featherless_biped *p)
{
	l->satisfied = false;
	pthread_mutex_lock(&l->mutex_thanatos);
	if (kronos_now() - p[l->i].last_time_eaten >= l->time_to_die)
	{
		l->thread_cut_by_atropos = true;
		pthread_mutex_lock(&l->mutex_printf);
		printf("%li %i died\n", kronos_now() - l->starting_time, p[l->i].id);
		pthread_mutex_unlock(&l->mutex_printf);
		pthread_mutex_unlock(&l->mutex_thanatos);
		return (false);
	}
	pthread_mutex_unlock(&l->mutex_thanatos);
	return (true);
}

void	wraper_threads_create(t_lyceum *l, t_featherless_biped *p)
{
	p->knowledge->starting_time = kronos_now();
	while (l->i < l->nbr_philos)
	{
		p[l->i].last_time_eaten = p->knowledge->starting_time;
		pthread_create(&p[l->i].thread_philo, NULL, routine_of_philo, &p[l->i]);
		l->i++;
	}
	pthread_mutex_lock(&l->sl.mutex_start_line);
	l->sl.all_set = true;
	pthread_mutex_unlock(&l->sl.mutex_start_line);
	l->i = 0;
}

bool	argos_core_loop(t_lyceum *l, t_featherless_biped *p)
{
	if ((l->amount_times_eat != -1))
	{
		pthread_mutex_lock(&l->mutex_amount_meal);
		if (p[l->i].amount_meals != l->amount_times_eat)
		{
			if (!end_simulation_verification(l, p))
			{
				pthread_mutex_unlock(&l->mutex_amount_meal);
				return (false);
			}
			pthread_mutex_unlock(&l->mutex_amount_meal);
		}
	}
	else
	{
		if (!end_simulation_verification(l, p))
			return (false);
	}
	return (true);
}
