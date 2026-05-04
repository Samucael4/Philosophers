/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:17:58 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 14:34:20 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	error_msg(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(STDERR_FILENO, str, size);
	exit(EXIT_FAILURE);
}

void	mutex_cleaner(t_lyceum *l, int amount)
{
	int	i;

	i = 0;
	while (i < amount)
		pthread_mutex_destroy(&l->mutex_fork[i++]);
}

void	clean_after_mutex(t_lyceum *l, int fail_index)
{
	pthread_mutex_destroy(&l->mutex_amount_meal);
	pthread_mutex_destroy(&l->mutex_printf);
	pthread_mutex_destroy(&l->mutex_thanatos);
	pthread_mutex_destroy(&l->sl.mutex_start_line);
	if (fail_index == -1)
		error_msg("Malloc fail!\n");
	else if (fail_index >= 0)
	{
		mutex_cleaner(l, fail_index);
		free(l->mutex_fork);
		error_msg("Mutex init fail!\n");
	}
}

void	clean_after_philos(t_lyceum *l)
{
	mutex_cleaner(l, l->nbr_forks);
	free(l->mutex_fork);
	pthread_mutex_destroy(&l->mutex_amount_meal);
	pthread_mutex_destroy(&l->mutex_printf);
	pthread_mutex_destroy(&l->mutex_thanatos);
	pthread_mutex_destroy(&l->sl.mutex_start_line);
	error_msg("Malloc fail!\n");
}

void	clean_all(t_featherless_biped *p, t_lyceum *l)
{
	int	i;

	i = 0;
	while (i < l->nbr_forks)
		pthread_mutex_destroy(&l->mutex_fork[i++]);
	pthread_mutex_destroy(&l->mutex_amount_meal);
	pthread_mutex_destroy(&l->mutex_printf);
	pthread_mutex_destroy(&l->mutex_thanatos);
	pthread_mutex_destroy(&l->sl.mutex_start_line);
	free(l->mutex_fork);
	free(p);
}
