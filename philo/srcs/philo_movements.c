/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:57:26 by smarques          #+#    #+#             */
/*   Updated: 2026/04/30 23:12:30 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	get_fork_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	pthread_mutex_lock(&p->knowledge->mutex_thanatos);
	if (!p->knowledge->thread_cut_by_atropos)
	{
		printf("%li %i has taken a fork\n", kronos_now()
			- p->knowledge->starting_time, p->id);
	}
	pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}

void	eat_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	pthread_mutex_lock(&p->knowledge->mutex_thanatos);
	if (!p->knowledge->thread_cut_by_atropos)
	{
		printf("%li %i is eating\n", kronos_now()
			- p->knowledge->starting_time, p->id);
	}
	pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}

void	sleep_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	pthread_mutex_lock(&p->knowledge->mutex_thanatos);
	if (!p->knowledge->thread_cut_by_atropos)
	{
		printf("%li %i is sleeping\n", kronos_now()
			- p->knowledge->starting_time, p->id);
	}
	pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}

void	think_mov(t_featherless_biped *p)
{
	bool	atropos;

	pthread_mutex_lock(&p->knowledge->mutex_thanatos);
	atropos = p->knowledge->thread_cut_by_atropos;
	pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	if (!atropos)
		printf("%li %i is thinking\n", kronos_now()
			- p->knowledge->starting_time, p->id);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}
