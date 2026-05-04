/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:17:42 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 13:50:19 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	taking_notes(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_amount_meal);
	p->amount_meals++;
	pthread_mutex_unlock(&p->knowledge->mutex_amount_meal);
	pthread_mutex_lock(&p->knowledge->mutex_thanatos);
	p->last_time_eaten = kronos_now();
	pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
}

bool	eating_release_forks(t_featherless_biped *p)
{
	if (!mini_sleeps(p->knowledge, kronos_now(), p->knowledge->time_to_eat))
	{
		pthread_mutex_unlock(p->l_fork);
		pthread_mutex_unlock(p->r_fork);
		return (false);
	}
	if (p->id % 2 != 0)
	{
		pthread_mutex_unlock(p->l_fork);
		pthread_mutex_unlock(p->r_fork);
	}
	else
	{
		pthread_mutex_unlock(p->r_fork);
		pthread_mutex_unlock(p->l_fork);
	}
	return (true);
}

void	think_a_little(t_featherless_biped *p)
{
	if (p->knowledge->time_to_sleep <= p->knowledge->time_to_eat)
	{
		if (p->knowledge->nbr_forks % 2 == 0)
			usleep((p->knowledge->time_to_eat - p->knowledge->time_to_sleep)
				* 1000);
		else
		{
			usleep((p->knowledge->time_to_eat * 2 - p->knowledge->time_to_sleep)
				* 1000);
		}
	}
}

bool	am_i_full(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_amount_meal);
	if (p->knowledge->amount_times_eat != -1)
	{
		if (p->amount_meals == p->knowledge->amount_times_eat)
		{
			pthread_mutex_unlock(&p->knowledge->mutex_amount_meal);
			return (true);
		}
	}
	pthread_mutex_unlock(&p->knowledge->mutex_amount_meal);
	return (false);
}

bool	routine_core_loop(t_featherless_biped *p)
{
	if (!life_checker(p))
		return (false);
	if (!forks_order_grab(p))
		return (false);
	taking_notes(p);
	eat_mov(p);
	if (!eating_release_forks(p))
		return (false);
	sleep_mov(p);
	if (!mini_sleeps(p->knowledge, kronos_now(), p->knowledge->time_to_sleep))
		return (false);
	think_mov(p);
	if (am_i_full(p))
		return (false);
	think_a_little(p);
	return (true);
}
