/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:41:03 by smarques          #+#    #+#             */
/*   Updated: 2026/04/21 12:04:05 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	parsing(int argc, char **argv, t_lyceum *l)
{
	if (argv)
		if (!valid_argv(argv))
			error_msg("Invalid format and chars for the arguments!\n");
	if (argc > 6 || (argc != 5 && argc != 6))
		error_msg("Invalid amount of arguments, need 4 or 5!\n");
	getting_proper_args(argc, argv, l);
}
