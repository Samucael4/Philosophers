/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/05/03 01:09:50 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

// HELPERS DA ROUTINE

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

void	*routine_of_philo(void *args)
{
	t_featherless_biped	*p;

	p = (t_featherless_biped *)args;
	while (1)
	{
		if (wait_all_start(p))
			break ;
		usleep(20);
	}
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!life_checker(p))
			break ;
		if (!forks_order_grab(p))
			break ;
		taking_notes(p);
		eat_mov(p);
		if (!eating_release_forks(p))
			break ;
		sleep_mov(p);
		if (!mini_sleeps(p->knowledge, kronos_now(),
				p->knowledge->time_to_sleep))
			break ;
		think_mov(p);
		if (am_i_full(p))
			break ;
		think_a_little(p);
	}
	return (NULL);
}

// NAO ESQUECER README
// PEDIR PARA REFAZEM OS TESTES
// OLHAR TESTES ANOTADO NOS PAPEIS
// REFAZER ABSURDOS NO PC DA ESCOLA

// HELPERS DA MAIN

int	main(int argc, char *argv[])
{
	t_lyceum			l;
	t_featherless_biped	*p;

	p = NULL;
	memset(&l, 0, sizeof(t_lyceum));
	parsing(argc, argv, &l);
	getting_ready_to_feast(&p, &l);
	wraper_threads_create(&l, p);
	while (1)
	{
		l.i = 0;
		l.satisfied = true;
		while (l.i < l.nbr_philos)
		{
			if (!argos_core_loop(&l, p))
				break ;
			l.i++;
		}
		if (l.satisfied || l.thread_cut_by_atropos)
			break ;
		usleep(20); // crair macro CPU_OVERLOAD_AVOIDER ou algo do genero
	}
	wraper_threads_join(&l, p);
	clean_all(p, &l);
	return (EXIT_SUCCESS);
}
