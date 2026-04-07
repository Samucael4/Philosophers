/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:08:10 by smarques          #+#    #+#             */
/*   Updated: 2026/04/08 00:05:25 by smarques         ###   ########.fr       */
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

void	error_argv_amount(void)
{
	char	*msg;
	int		size;

	msg = "Invalid amount of arguments, need 4 or 5!\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}

void	error_exec_clean(void)
{
	char *msg;
	int size;

	// chamar funcoes de clean e free de tudo
	msg = "Possible error in malloc or in execution\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}

void	clean_all()
{
	
}