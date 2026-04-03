/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:19:31 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/19 13:57:27 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
	{
		printf("Error: Unable to use getimeofday.\n");
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
