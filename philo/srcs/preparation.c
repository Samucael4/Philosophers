/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:08:18 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 14:55:14 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	setting_table(t_lyceum *l)
{
	int	i;

	i = 0;
	l->mutex_fork = malloc(sizeof(pthread_mutex_t) * l->nbr_forks);
	if (!l->mutex_fork)
		return (-1);
	while (i < l->nbr_forks)
	{
		if (pthread_mutex_init(&l->mutex_fork[i], NULL))
			return (i);
		i++;
	}
	return (-2);
}

static void	getting_philo_data(t_featherless_biped **p, t_lyceum *l, int i)
{
	(*p)[i].r_fork = &l->mutex_fork[i];
	(*p)[i].id = i + 1;
	(*p)[i].knowledge = l;
	(*p)[i].amount_meals = 0;
	(*p)[i].last_time_eaten = kronos_now();
}

static bool	make_faetherless_bipes(t_featherless_biped **p, t_lyceum *l)
{
	bool	firts_philo;
	int		i;

	firts_philo = true;
	i = 0;
	*p = malloc(sizeof(t_featherless_biped) * l->nbr_philos);
	if (!*p)
		return (false);
	while (i < l->nbr_philos)
	{
		(*p)[i].r_fork = NULL;
		(*p)[i].l_fork = NULL;
		if (firts_philo)
		{
			getting_philo_data(p, l, i);
			(*p)[i].l_fork = &l->mutex_fork[l->nbr_forks - 1];
			firts_philo = false;
			i++;
			continue ;
		}
		getting_philo_data(p, l, i);
		(*p)[i].l_fork = &l->mutex_fork[i - 1];
		i++;
	}
	return (true);
}

void	safe_mutiexs_init(t_lyceum *l)
{
	if (pthread_mutex_init(&l->sl.mutex_start_line, NULL))
		error_msg("Mutex init fail!\n");
	if (pthread_mutex_init(&l->mutex_printf, NULL))
	{
		pthread_mutex_destroy(&l->sl.mutex_start_line);
		error_msg("Mutex init fail!\n");
	}
	if (pthread_mutex_init(&l->mutex_thanatos, NULL))
	{
		pthread_mutex_destroy(&l->mutex_printf);
		pthread_mutex_destroy(&l->sl.mutex_start_line);
		error_msg("Mutex init fail!\n");
	}
	if (pthread_mutex_init(&l->mutex_amount_meal, NULL))
	{
		pthread_mutex_destroy(&l->mutex_thanatos);
		pthread_mutex_destroy(&l->mutex_printf);
		pthread_mutex_destroy(&l->sl.mutex_start_line);
		error_msg("Mutex init fail!\n");
	}
}

void	getting_ready_to_feast(t_featherless_biped **p, t_lyceum *l)
{
	int	set_table_status;

	safe_mutiexs_init(l);
	set_table_status = setting_table(l);
	if (set_table_status != -2)
		clean_after_mutex(l, set_table_status);
	if (!make_faetherless_bipes(p, l))
		clean_after_philos(l);
	l->sl.all_set = false;
}
