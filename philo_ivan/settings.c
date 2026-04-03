/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:26:49 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/19 14:44:40 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_settings	set_settings(int argc, char **argv)
{
	t_settings	set;

	set.num_philo = ft_atol(argv[1]);
	set.time_to_die = ft_atol(argv[2]);
	set.time_to_eat = ft_atol(argv[3]);
	set.time_to_sleep = ft_atol(argv[4]);
	set.all_threads_created = 0;
	set.stop_simulation = 0;
	set.num_required_meals = -1;
	if (argc == 6)
		set.num_required_meals = ft_atol(argv[5]);
	return (set);
}
