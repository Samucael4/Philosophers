/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:10:49 by smarques          #+#    #+#             */
/*   Updated: 2026/04/11 18:45:52 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

long	ft_atol(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
		number = (number * 10) + (*str++ - '0');
	return ((number * sign));
}
