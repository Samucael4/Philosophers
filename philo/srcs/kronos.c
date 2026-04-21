/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kronos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 11:44:51 by smarques          #+#    #+#             */
/*   Updated: 2026/04/21 12:04:46 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

long	time_now()
{
	struct timeval	tv;
	long			time;
	long			seconds;
	long			micro_seconds;

	if (gettimeofday(&tv, NULL) == -1)
		error_msg("Failed function call gettimeofday!\n");
	seconds = tv.tv_sec * 1000;
	micro_seconds = tv.tv_usec / 1000;
	time = seconds + micro_seconds;
	return (time);
}
