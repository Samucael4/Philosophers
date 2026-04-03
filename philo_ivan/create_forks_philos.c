/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_forks_philos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:20:19 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/19 14:48:10 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*create_forks(t_settings *settings)
{
	int		i;
	int		res;
	t_fork	*forks;

	forks = malloc(sizeof(t_fork) * settings->num_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < settings->num_philo)
	{
		forks[i].id = i;
		res = pthread_mutex_init(&forks[i].mutex, NULL);
		if (res != 0)
			return (NULL);
		i++;
	}
	return (forks);
}

static void	assign_forks(t_philo *philo, t_fork *forks, int num_philo)
{
	if (philo->id % 2 == 0)
	{
		philo->left_hand = &forks[philo->id - 1];
		philo->right_hand = &forks[ft_mod(philo->id - 2, num_philo)];
	}
	else
	{
		philo->left_hand = &forks[ft_mod(philo->id - 2, num_philo)];
		philo->right_hand = &forks[philo->id - 1];
	}
}

static void	init_philo(t_philo *philo, int id, t_settings *set, t_fork *forks)
{
	philo->id = id + 1;
	philo->meals_eaten = 0;
	philo->status = THINKING;
	philo->last_meal = get_current_time();
	philo->settings = set;
	philo->forks = forks;
	assign_forks(philo, forks, set->num_philo);
}

t_philo	*create_philo(t_settings *set, t_fork *forks)
{
	t_philo	*philos;
	int		i;

	philos = malloc(sizeof(t_philo) * set->num_philo);
	if (!philos)
		return (NULL);
	i = 0;
	while (i < set->num_philo)
	{
		init_philo(&philos[i], i, set, forks);
		i++;
	}
	return (philos);
}
