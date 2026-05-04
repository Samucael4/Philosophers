/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 15:01:15 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine_of_philo(void *args)
{
	t_featherless_biped	*p;

	p = (t_featherless_biped *)args;
	while (1)
	{
		if (wait_all_start(p))
			break ;
		usleep(20);
	}
	if (p->id % 2 == 0)
		usleep(100);
	while (1)
	{
		if (!routine_core_loop(p))
			break ;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_lyceum			l;
	t_featherless_biped	*p;

	p = NULL;
	memset(&l, 0, sizeof(t_lyceum));
	parsing(argc, argv, &l);
	getting_ready_to_feast(&p, &l);
	safe_threads_create(wraper_threads_create(&l, p), &l, p);
	while (1)
	{
		l.i = 0;
		l.satisfied = true;
		while (l.i < l.nbr_philos)
		{
			if (!argos_core_loop(&l, p))
				break ;
			l.i++;
		}
		if (l.satisfied || l.thread_cut_by_atropos)
			break ;
		usleep(20);
	}
	wraper_threads_join(&l, p);
	clean_all(p, &l);
	return (EXIT_SUCCESS);
}
