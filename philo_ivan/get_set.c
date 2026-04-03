/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:12:23 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/22 01:00:12 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_long_mtx(pthread_mutex_t *mtx, unsigned long *target,
		unsigned long value)
{
	pthread_mutex_lock(mtx);
	*target = value;
	pthread_mutex_unlock(mtx);
}

unsigned long	get_long_mtx(pthread_mutex_t *mtx, unsigned long *value)
{
	long	result;

	pthread_mutex_lock(mtx);
	result = *value;
	pthread_mutex_unlock(mtx);
	return (result);
}

void	set_int_mtx(pthread_mutex_t *mtx, int *target, int value)
{
	pthread_mutex_lock(mtx);
	*target = value;
	pthread_mutex_unlock(mtx);
}

int	get_int_mtx(pthread_mutex_t *mtx, int *value)
{
	int	res;

	pthread_mutex_lock(mtx);
	res = *value;
	pthread_mutex_unlock(mtx);
	return (res);
}
