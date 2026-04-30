/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/04/30 18:59:51 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

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

void	*routine_of_philo(void *args)
{
	int					i;
	bool				death_check;
	t_featherless_biped	*p;

	p = (t_featherless_biped *)args;
	i = 0;
	while (1)
	{
		if (wait_all_start(p))
			break ;
		usleep(100);
	}
	while (1)
	{
		pthread_mutex_lock(&p->knowledge->mutex_thanatos);
		death_check = p->knowledge->thread_cut_by_atropos;
		pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
		if (death_check)
			break ;
		if (p->id % 2 != 0)
		{
			pthread_mutex_lock(p->r_fork);
			if (p->knowledge->nbr_forks > 1)
				pthread_mutex_lock(p->l_fork);
			else
			{
				pthread_mutex_lock(&p->knowledge->mutex_printf);
				printf("%li %i has taken a fork\n", kronos_now()
					- p->knowledge->starting_time, p->id);
				pthread_mutex_unlock(&p->knowledge->mutex_printf);
				while (!p->knowledge->thread_cut_by_atropos)
					usleep(10);
			}
		}
		else
		{
			if (p->knowledge->nbr_forks > 1)
				pthread_mutex_lock(p->l_fork);
			pthread_mutex_lock(p->r_fork);
		}
		get_fork_mov(p);
		if (p->knowledge->nbr_forks > 1)
			get_fork_mov(p);
		pthread_mutex_lock(&p->knowledge->mutex_amount_meal);
		p->amount_meals++;
		pthread_mutex_unlock(&p->knowledge->mutex_amount_meal);
		pthread_mutex_lock(&p->knowledge->mutex_thanatos);
		p->last_time_eaten = kronos_now();
		pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
		pthread_mutex_lock(&p->knowledge->mutex_thanatos);
		death_check = p->knowledge->thread_cut_by_atropos;
		pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
		if (death_check)
		{
			if (p->knowledge->nbr_forks > 1)
				pthread_mutex_unlock(p->l_fork);
			pthread_mutex_unlock(p->r_fork);
			break ;
		}
		eat_mov(p);
		usleep(p->knowledge->time_to_eat * 1000);
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
		pthread_mutex_lock(&p->knowledge->mutex_thanatos);
		death_check = p->knowledge->thread_cut_by_atropos;
		pthread_mutex_unlock(&p->knowledge->mutex_thanatos);
		if (death_check)
			break ;
		sleep_mov(p);
		usleep(p->knowledge->time_to_sleep * 1000);
		think_mov(p);
		pthread_mutex_lock(&p->knowledge->mutex_amount_meal);
		if (p->knowledge->amount_times_eat != -1)
		{
			if (p->amount_meals == p->knowledge->amount_times_eat)
			{
				pthread_mutex_unlock(&p->knowledge->mutex_amount_meal);
				break ;
			}
		}
		pthread_mutex_unlock(&p->knowledge->mutex_amount_meal);
		if (p->knowledge->time_to_sleep < p->knowledge->time_to_eat)
		{
			if (p->knowledge->nbr_forks % 2 == 0)
				usleep((p->knowledge->time_to_eat - p->knowledge->time_to_sleep)
					* 1000);
			else
			{
				usleep((p->knowledge->time_to_eat * 2
						- p->knowledge->time_to_sleep) * 1000);
			}
		}
		i++;
	}
	return (NULL);
}

// NAO ESQUECER README

int	main(int argc, char *argv[])
{
	t_lyceum			l;
	t_featherless_biped	*p;
	bool				meals_checker;
	long				last_meal_checker;

	memset(&l, 0, sizeof(t_lyceum));
	p = NULL;
	parsing(argc, argv, &l);
	getting_ready_to_feast(&p, &l);
	p->knowledge->starting_time = kronos_now();
	while (l.i < l.nbr_philos)
	{
		p[l.i].last_time_eaten = p->knowledge->starting_time;
		pthread_create(&p[l.i].thread_philo, NULL, routine_of_philo, &p[l.i]);
		l.i++;
	}
	pthread_mutex_lock(&l.sl.mutex_start_line);
	l.sl.all_set = true;
	pthread_mutex_unlock(&l.sl.mutex_start_line);
	l.i = 0;
	while (1)
	{
		l.i = 0;
		l.satisfied = true;
		while (l.i < l.nbr_philos)
		{
			if ((l.amount_times_eat != -1)) // significa que tem limite
			{
				pthread_mutex_lock(&l.mutex_amount_meal);
				meals_checker = p[l.i].amount_meals != l.amount_times_eat;
				pthread_mutex_unlock(&l.mutex_amount_meal);
				if (meals_checker)
				{
					l.satisfied = false;
					pthread_mutex_lock(&l.mutex_thanatos);
					last_meal_checker = kronos_now() - p[l.i].last_time_eaten;
					pthread_mutex_unlock(&l.mutex_thanatos);
					if (last_meal_checker > l.time_to_die)
					{
						pthread_mutex_lock(&l.mutex_thanatos);
						l.thread_cut_by_atropos = true;
						pthread_mutex_unlock(&l.mutex_thanatos);
						pthread_mutex_lock(&l.mutex_printf);
						printf("%li %i died\n", kronos_now() - l.starting_time,
							p[l.i].id);
						pthread_mutex_unlock(&l.mutex_printf);
						break ;
					}
				}
			}
			else // nao tem limite de comidas
			{
				l.satisfied = false;
				pthread_mutex_lock(&l.mutex_thanatos);
				last_meal_checker = kronos_now() - p[l.i].last_time_eaten;
				pthread_mutex_unlock(&l.mutex_thanatos);
				if (last_meal_checker > l.time_to_die)
				{
					pthread_mutex_lock(&l.mutex_thanatos);
					l.thread_cut_by_atropos = true;
					pthread_mutex_unlock(&l.mutex_thanatos);
					pthread_mutex_lock(&l.mutex_printf);
					printf("%li %i died\n", kronos_now() - l.starting_time,
						p[l.i].id);
					pthread_mutex_unlock(&l.mutex_printf);
					break ;
				}
			}
			l.i++;
		}
		// acho legar proteger com mutex aqui
		if (l.satisfied || l.thread_cut_by_atropos)
			break ;
		usleep(100);
	}
	l.i = 0;
	while (l.i < l.nbr_philos)
	{
		pthread_join(p[l.i].thread_philo, NULL);
		l.i++;
	}
	clean_all(p, &l);
	return (EXIT_SUCCESS);
}
