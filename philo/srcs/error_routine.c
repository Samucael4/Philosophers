/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 00:08:10 by smarques          #+#    #+#             */
/*   Updated: 2026/04/18 19:14:15 by smarques         ###   ########.fr       */
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

	caso na hora de init nas mutex, tem que dar destroy nas que foram inicalizadas,
	ou destroy so serve para threads?
*/

void	error_exec_clean(t_lyceum *l, t_featherless_biped *p)
{
	char	*msg;
	int		size;

	(void) p;
	(void) l;
	// chamar funcoes de clean e free de tudo
	msg = "Possible error in malloc or in execution\n";
	size = ft_strlen(msg);
	write(STDERR_FILENO, msg, size);
	exit(EXIT_FAILURE);
}
