/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:56:04 by smarques          #+#    #+#             */
/*   Updated: 2026/04/22 13:26:14 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

bool	valid_argv(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0)
			{
				if (av[i][j] == '+')
				{
					j++;
					continue ;
				}
			}
			if (!ft_isdigit(av[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

// correto checar 0 para todos?
void	int_checker(t_lyceum *l, int argc)
{
	(void)argc;
	if (l->nbr_philos > INT_MAX || l->nbr_philos <= 0)
		error_msg("Ridiculous size of argument, try something normal!\n");
	if (l->time_to_die > INT_MAX || l->time_to_die <= 0)
		error_msg("Ridiculous size of argument, try something normal!\n");
	if (l->time_to_eat > INT_MAX || l->time_to_eat <= 0)
		error_msg("Ridiculous size of argument, try something normal!\n");
	if (l->time_to_sleep > INT_MAX || l->time_to_sleep <= 0)
		error_msg("Ridiculous size of argument, try something normal!\n");
	if (argc == 6)
	{
		if ((l->amount_times_eat && l->amount_times_eat > INT_MAX)
			|| l->amount_times_eat <= 0)
			error_msg("Ridiculous size of argument, try something normal!\n");
	}
}

void	getting_proper_args(int argc, char **argv, t_lyceum *l)
{
	l->nbr_philos = ft_atol(argv[1]);
	l->time_to_die = ft_atol(argv[2]);
	l->time_to_eat = ft_atol(argv[3]);
	l->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		l->amount_times_eat = ft_atol(argv[5]);
	else
		l->amount_times_eat = -1;
	int_checker(l, argc);
	l->nbr_forks = l->nbr_philos;
	l->i = 0;
	l->mutex_fork = NULL;
}
