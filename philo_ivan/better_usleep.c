/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:16:17 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/19 13:59:09 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	better_usleep(long milis, t_settings *set)
{
	long	now;

	now = get_current_time();
	while ((get_current_time() - now < milis) && !check_stop_condition(set))
		usleep(500);
}
