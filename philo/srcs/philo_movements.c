/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:57:26 by smarques          #+#    #+#             */
/*   Updated: 2026/04/22 16:30:20 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	get_fork_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	printf("%li %i has taken a fork\n", time_now()
		- p->knowledge->starting_time, p->id);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}

void	eat_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	printf("%li %i is eating\n", time_now() - p->knowledge->starting_time,
		p->id);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}

void	sleep_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	printf("%li %i is sleeping\n", time_now() - p->knowledge->starting_time,
		p->id);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}

void	think_mov(t_featherless_biped *p)
{
	pthread_mutex_lock(&p->knowledge->mutex_printf);
	printf("%li %i is thinking\n", time_now() - p->knowledge->starting_time,
		p->id);
	pthread_mutex_unlock(&p->knowledge->mutex_printf);
}