/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:08:18 by smarques          #+#    #+#             */
/*   Updated: 2026/05/02 19:11:48 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

// mudar para int, se der tudo certo, retornar -1
// se der erro, retorna i, que eh o index que deu errado
// isso vai ajudar a criar um loop para dar
// destroy nas mutex criadas ate entao e limpar tudo
// verificar retorno de todas as funcoes

static bool	setting_table(t_lyceum *l)
{
	int	i;

	i = 0;
	l->mutex_fork = malloc(sizeof(pthread_mutex_t) * l->nbr_forks);
	if (!l->mutex_fork)
		return (false);
	while (i < l->nbr_forks)
	{
		if (pthread_mutex_init(&l->mutex_fork[i], NULL))
			return (false);
		i++;
	}
	return (true);
}

static void	getting_philo_data(t_featherless_biped **p, t_lyceum *l, int i)
{
	(*p)[i].r_fork = &l->mutex_fork[i];
	(*p)[i].id = i + 1;
	(*p)[i].knowledge = l;
	(*p)[i].amount_meals = 0;
	(*p)[i].last_time_eaten = kronos_now();
}

static bool	make_faetherless_bipes(t_featherless_biped **p, t_lyceum *l)
{
	bool	firts_philo;
	int		i;

	firts_philo = true;
	i = 0;
	*p = malloc(sizeof(t_featherless_biped) * l->nbr_philos);
	if (!*p)
		return (false);
	while (i < l->nbr_philos)
	{
		(*p)[i].r_fork = NULL;
		(*p)[i].l_fork = NULL;
		if (firts_philo)
		{
			getting_philo_data(p, l, i);
			(*p)[i].l_fork = &l->mutex_fork[l->nbr_forks - 1];
			firts_philo = false;
			i++;
			continue ;
		}
		getting_philo_data(p, l, i);
		(*p)[i].l_fork = &l->mutex_fork[i - 1];
		i++;
	}
	return (true);
}

void	getting_ready_to_feast(t_featherless_biped **p, t_lyceum *l)
{
	if (!setting_table(l))
		write(2, "erro", 4); // exec clean em tudo
	if (!make_faetherless_bipes(p, l))
		write(2, "erro", 4); // exec_clean em tudo ate agr
	pthread_mutex_init(&l->sl.mutex_start_line, NULL);
	// rever se tem que colcoar algo especifico em NULL
	// e tbm ver do que se trata esse arg
	// tem que verificar as criacoes das theads??
	pthread_mutex_init(&l->mutex_printf, NULL);
	pthread_mutex_init(&l->mutex_thanatos, NULL);
	pthread_mutex_init(&l->mutex_amount_meal, NULL);
	l->sl.all_set = false;
}
