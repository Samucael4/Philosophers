/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:10:49 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 13:50:36 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
		number = (number * 10) + (*str++ - '0');
	return ((number * sign));
}

long	kronos_now(void)
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

bool	mini_sleeps(t_lyceum *l, long start_action, long time_action)
{
	while ((kronos_now() - start_action) < time_action)
	{
		pthread_mutex_lock(&l->mutex_thanatos);
		if (l->thread_cut_by_atropos)
		{
			pthread_mutex_unlock(&l->mutex_thanatos);
			return (false);
		}
		pthread_mutex_unlock(&l->mutex_thanatos);
		usleep(500);
	}
	return (true);
}
