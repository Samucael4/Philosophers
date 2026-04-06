/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/04/07 00:18:13 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

int main(int argc, char *argv[])
{
	if (argv)
		if (!valid_argv(argv))
			error_argv_checker();
	if (argc > 6) // funcao de print erro, e sair basica, sem leaks
	{
		;
	}
	if (argc == 5) // caso sem opcao bonus
	{
		;
	}
	else
	{
		;
	}
	return (EXIT_SUCCESS);
}
