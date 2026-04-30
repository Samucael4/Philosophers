/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:17:58 by smarques          #+#    #+#             */
/*   Updated: 2026/04/30 19:01:18 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

// coisas alocadas dentro de cada struct:
/*
MANTER ATUALIZADO PARA VER O QUE TA SENDO ALOCADA, CASO DE ERRO CHAMAR
EXEC_CLEAN QUE VAI PERCORRER TUDO LIMPANDO AS STRUCTS
E OS ITENS DENTRO DELAS

FEATHERLESS_BIPED:
o featherless_biped em si eh um array de structs
	para cada philo eu tenho que ver o que ta sendo alocado (por hora nada)

LYCEUM:
no lyceum tem o array de mutex
	por hora nao ha nada sendo alocado dentro de lyceum

	caso na hora de init nas mutex,
		tem que dar destroy nas que foram inicalizadas,
	ou destroy so serve para threads?
*/

void	error_msg(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(STDERR_FILENO, str, size);
	exit(EXIT_FAILURE);
}

void	error_exec_clean(t_lyceum *l, t_featherless_biped *p)
{
	char	*msg;
	int		size;

	(void)p;
	(void)l;
	// chamar funcoes de clean e free de tudo
	// ver se necessario destroy mutex
	msg = "Possible error in malloc or in execution\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}

void	clean_all(t_featherless_biped *p, t_lyceum *l)
{
	// melhorar essa fucnao para verificar
	// se algo nao eh null, pq vou chamar ela
	// em varios lugares que pode ter nada ainda mallocado
	// ex: setting table pode flahar antes de criar os philos
	// mas to dando free neles aqui, o que vai dar erro
	int i;

	i = 0;
	while (i < l->nbr_forks)
		pthread_mutex_destroy(&l->mutex_fork[i++]);
	pthread_mutex_destroy(&l->mutex_amount_meal);
	pthread_mutex_destroy(&l->mutex_printf);
	pthread_mutex_destroy(&l->mutex_thanatos);
	pthread_mutex_destroy(&l->sl.mutex_start_line);
	free(l->mutex_fork);
	free(p);
}
