/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:08:10 by smarques          #+#    #+#             */
/*   Updated: 2026/04/07 00:18:01 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	error_argv_checker()
{
	char	*msg;
	int		size;

	msg = "Invalid format and chars for the arguments!\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}
