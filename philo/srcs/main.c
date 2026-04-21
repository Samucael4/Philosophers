/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 21:19:51 by smarques          #+#    #+#             */
/*   Updated: 2026/04/21 16:44:12 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philophers.h"

// mudar para int, se der tudo certo, retornar -1
// se der erro, retorna i, que eh o index que deu errado
// isso vai ajudar a criar um loop para dar
// destroy nas mutex criadas ate entao e limpar tudo
bool	setting_table(t_lyceum *l)
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

// preciso rever o que tem que ser verificado caso null
// adcionei verificacoes e etapas a mais, preciso ver se os ajustes esto
// certo e coerentes / testar com e sem para ver resultado
bool	make_faetherless_bipes(t_featherless_biped **p, t_lyceum *l)
{
	int		i;
	int		size;
	bool	firts_philo;

	firts_philo = true;
	i = 0;
	size = sizeof(t_featherless_biped) * l->nbr_philos;
	*p = malloc(size);
	if (!*p)
		return (false);
	while (i < l->nbr_philos)
	{
		(*p)[i].r_fork = NULL;
		(*p)[i].l_fork = NULL;
		if (firts_philo)
		{
			(*p)[i].r_fork = &l->mutex_fork[i];
			(*p)[i].l_fork = &l->mutex_fork[l->nbr_forks - 1];
			(*p)[i].id = i;
			(*p)[i].knowledge = l;
			firts_philo = false;
			i++;
			continue ;
		}
		(*p)[i].r_fork = &l->mutex_fork[i];
		(*p)[i].l_fork = &l->mutex_fork[i - 1];
		(*p)[i].id = i;
		(*p)[i].knowledge = l;
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
	l->sl.all_set = false;
}

// change the struct typre
void	*routine_of_philo(void *args)
{
	int					i;
	t_featherless_biped	*p;

	p = (t_featherless_biped *)args;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&p->knowledge->sl.mutex_start_line);
		if (p->knowledge->sl.all_set)
		{
			pthread_mutex_unlock(&p->knowledge->sl.mutex_start_line);
			break ;
		}
		pthread_mutex_unlock(&p->knowledge->sl.mutex_start_line);
		usleep(100);
	}
	while (1)
	{
		if (p->id % 2 == 0)
			usleep(1000);
		pthread_mutex_unlock(p->r_fork);
		pthread_mutex_unlock(p->l_fork);
		printf("%li %i has taken a fork\n", time_now()
			- p->knowledge->starting_time, p->id);
		p->last_time_eaten = time_now();
		printf("%li %i is eating\n", time_now() - p->knowledge->starting_time,
			p->id);
		usleep(p->knowledge->time_to_eat);
		pthread_mutex_unlock(p->r_fork);
		pthread_mutex_unlock(p->l_fork);
		printf("%li %i is sleeping\n", time_now() - p->knowledge->starting_time,
			p->id);
		usleep(p->knowledge->time_to_sleep);
		printf("%li %i is thinking\n", time_now() - p->knowledge->starting_time,
			p->id);
		if (i == p->knowledge->amount_times_eat)
			break ;
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_lyceum			l;
	t_featherless_biped	*p;

	p = NULL;
	parsing(argc, argv, &l);
	getting_ready_to_feast(&p, &l);
	// criar as threads
	while (l.i < l.nbr_philos)
	{
		pthread_create(&p[l.i].thread_philo, NULL, routine_of_philo, &p[l.i]);
		l.i++;
	}
	// testar a ordem das duas linha de baixo
	p->knowledge->starting_time = time_now();
	pthread_mutex_lock(&l.sl.mutex_start_line);
	l.sl.all_set = true;
	pthread_mutex_unlock(&l.sl.mutex_start_line);
	l.i = 0;
	// qual a real necessidade do pthread_join???
	while (l.i < l.nbr_philos)
	{
		// reviar a necessidad do segundo arg
		pthread_join(p[l.i].thread_philo, NULL);
		l.i++;
	}
	// clean_all();
	return (EXIT_SUCCESS);
}

/*duvidas
adcionei barreira de inicio para esperar o while crair todas as threads para so depois
comecar a fazer a rotina*/

/*o que faz segunda arg da mutex_init e pq ta null?
"Crie uma função que usa o gettimeofday (eu vi que você já testou
isso na sua pasta de testes!) para pegar o tempo atual em milissegundos e salvar nessa variável
logo antes de criar as threads." isso que voce
falou nao eh perigoso? nao leva tempo para criar a threads?
isso nao causaria uma decincronissidade de tempo?*/