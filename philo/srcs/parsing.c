/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:41:03 by smarques          #+#    #+#             */
/*   Updated: 2026/04/11 18:59:13 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	parsing(int argc, char **argv, t_lyceum *l)
{
	if (argv)
		if (!valid_argv(argv))
			error_argv_checker();
	if (argc > 6 || (argc != 5 && argc != 6))
		error_argv_amount();
	getting_proper_args(argv, l);
}