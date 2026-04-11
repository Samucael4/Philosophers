/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeday.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 16:36:42 by smarques          #+#    #+#             */
/*   Updated: 2026/04/08 16:37:18 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

int	main(int argc, char const *argv[])
{
	int verificacao_time_day;
	struct timeval hora;
	long total_tmp;

	// isso aqui da valor em microsegundos, preciso trabalhar com milisegundos
	verificacao_time_day = gettimeofday(&hora, NULL);
	if (verificacao_time_day == 0)
	{
		total_tmp = hora.tv_usec * 1000;
		total_tmp += hora.tv_usec / 1000;
		printf("real_time: %li || micro: %li || epoch: %li\n", total_tmp,
			hora.tv_usec, hora.tv_sec);
	}
	return (EXIT_SUCCESS);
}
