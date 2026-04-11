/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:08:10 by smarques          #+#    #+#             */
/*   Updated: 2026/04/11 19:18:40 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	error_exec_clean(void)
{
	char	*msg;
	int		size;

	// chamar funcoes de clean e free de tudo
	msg = "Possible error in malloc or in execution\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}
