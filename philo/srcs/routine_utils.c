/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 12:18:53 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 13:50:31 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

bool	wait_all_start(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->sl.mutex_start_line);
	if (p->knowledge->sl.all_set)
	{
		pthread_mutex_unlock(&p->knowledge->sl.mutex_start_line);
		return (true);
	}
	pthread_mutex_unlock(&p->knowledge->sl.mutex_start_line);
	return (false);
}

bool	life_checker(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_thanatos);
	if (p->knowledge->thread_cut_by_atropos)
	{
		pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
		return (false);
	}
	pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
	return (true);
}

void	enven_order_grab(t_featherless_biped *p)
{
	pthread_mutex_lock(p->l_fork);
	pthread_mutex_lock(p->r_fork);
}

void	odd_order_grab(t_featherless_biped *p)
{
	pthread_mutex_lock(p->r_fork);
	if (p->knowledge->nbr_forks > 1)
		pthread_mutex_lock(p->l_fork);
}

bool	forks_order_grab(t_featherless_biped *p)
{
	if (p->id % 2 != 0)
	{
		odd_order_grab(p);
		if (p->knowledge->nbr_philos == 1)
		{
			pthread_mutex_lock(&p->knowledge->mutex_printf);
			printf("%li %i has taken a fork\n", kronos_now()
				- p->knowledge->starting_time, p->id);
			pthread_mutex_unlock(&p->knowledge->mutex_printf);
			pthread_mutex_lock(&p->knowledge->mutex_thanatos);
			while (!p->knowledge->thread_cut_by_atropos)
			{
				pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
				usleep(10);
				pthread_mutex_lock(&p->knowledge->mutex_thanatos);
			}
			pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
			pthread_mutex_unlock(p->r_fork);
			return (false);
		}
	}
	else
		enven_order_grab(p);
	get_fork_mov(p);
	return (true);
}
