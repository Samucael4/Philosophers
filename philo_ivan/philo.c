/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:01:37 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/26 18:04:01 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int	init_mutex(t_settings *set, t_philo *philos)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	res = pthread_mutex_init(&set->all_threads_mtx, NULL);
	res += pthread_mutex_init(&set->printf_mutex, NULL);
	res += pthread_mutex_init(&set->started_mtx, NULL);
	res += pthread_mutex_init(&set->stop_mtx, NULL);
	while (i < set->num_philo)
	{
		res += pthread_mutex_init(&philos[i].last_meal_mtx, NULL);
		res += pthread_mutex_init(&philos[i].meals_eaten_mtx, NULL);
		res += pthread_mutex_init(&philos[i].status_mtx, NULL);
		i++;
	}
	set->all_threads_created = 0;
	return (res);
}

static int	validate_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (write(2, "Error: invalid number of arguments\n", 35), -1);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (write(2, "Error: positive arguments only.\n", 33), -1);
			j++;
		}
		if (ft_atol(argv[i]) <= 0)
			return (write(2, "Error: args. only greater than zero.\n", 38), -1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_settings	settings;
	t_philo		*philos;
	t_fork		*forks;

	if (validate_args(argc, argv) != 0)
		return (1);
	settings = set_settings(argc, argv);
	forks = create_forks(&settings);
	if (!forks)
		return (1);
	philos = create_philo(&settings, forks);
	if (!philos)
		return (free(forks), 1);
	if (init_mutex(&settings, philos) != 0)
		return (clean(&settings, philos, forks), 1);
	if (start_simulation(&settings, philos) < 0)
		return (clean(&settings, philos, forks), 1);
	clean(&settings, philos, forks);
	return (0);
}
