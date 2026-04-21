/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:17:58 by smarques          #+#    #+#             */
/*   Updated: 2026/04/15 00:07:39 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

void	error_msg(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(STDERR_FILENO, str, size);
	exit(EXIT_FAILURE);
}
