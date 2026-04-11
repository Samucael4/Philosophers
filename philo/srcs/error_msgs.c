/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:17:58 by smarques          #+#    #+#             */
/*   Updated: 2026/04/11 19:18:32 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	error_argv_checker(void)
{
	char	*msg;
	int		size;

	msg = "Invalid format and chars for the arguments!\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}

void	error_nbr_size(void)
{
	char	*msg;
	int		size;

	msg = "Ridiculous size of argument, try something normal!\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}

void	error_argv_amount(void)
{
	char *msg;
	int size;

	msg = "Invalid amount of arguments, need 4 or 5!\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}