/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/04/08 00:06:34 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	lyceum_starter(t_lyceum *l)
{
	l->nbr_forks = 0;
	l->nbr_philos = 0;
	l->time_to_die = 0;
	l->time_to_eat = 0;
	l->time_to_sleep = 0;
	l->amount_times_eat = 0;
}

bool	thinking(int argc, t_lyceum *l, t_featherless_biped *p)
{
	if (argc == 5)
	{
		;
	}
	else
	{
		;
	}
}

int	main(int argc, char *argv[])
{
	t_lyceum			l;
	t_featherless_biped	p;

	if (argv)
		if (!valid_argv(argv))
			error_argv_checker();
	if (argc > 6 || argc != 5 || argc != 6)
		error_argv_amount();
	lyceum_starter(&l);
	if (!thinking(argc, &l, &p))
		error_exec_clean();
	clean_all();
	return (EXIT_SUCCESS);
}
