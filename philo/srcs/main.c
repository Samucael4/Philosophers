/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/04/11 19:29:17 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

/* bool	thinking(int argc, t_lyceum *l, t_featherless_biped *p)
{
	int i;

	i = 0;
	while (i < l->nbr_philos)
	{

	}
} */

void check_lycem_vars(t_lyceum l) // apenas para debug
{
	printf("nº philos:%li\n", l.nbr_philos);
	printf("time to die:%li\n", l.time_to_die);
	printf("time to eat:%li\n", l.time_to_eat);
	printf("time to sleep:%li\n", l.time_to_sleep);
	if (l.amount_times_eat != -1)
		printf("qntd to eat:%li\n", l.amount_times_eat);
}

int	main(int argc, char *argv[])
{
	t_lyceum			l;
	t_featherless_biped	*p;

	parsing(argc, argv, &l);
	getting_proper_args(argv, &l);
	// debug strt
	check_lycem_vars(l);
	// end debug
	p = malloc(sizeof(t_featherless_biped) * l.nbr_philos);
	if (!p)
		// rotina limpeza e ver o que ta alocado ate aqui
	/* if (!thinking(argc, &l, p))
		error_exec_clean();
	clean_all(); */
	return (EXIT_SUCCESS);
}
