/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philophers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:24:31 by smarques          #+#    #+#             */
/*   Updated: 2026/04/11 19:25:58 by smarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>  // pthread_create, pthread_detach, pthread_join,
# include <stdbool.h>  // bool type
# include <stdio.h>    // printf
# include <stdlib.h>   // malloc, free
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write, usleep
						// pthread_mutex_init, pthread_mutex_destroy,
						// pthread_mutex_lock, pthread_mutex_unloc
# include <limits.h>   // MAX/MIN_INT

typedef struct s_lyceum
{
	long				nbr_philos;
	long				nbr_forks;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				amount_times_eat;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_print;
	pthread_mutex_t	monitor_meal;
}					t_lyceum;

typedef struct s_featherless_biped
{
	int				id;
	long			last_meal;
	long			amount_meals;
	pthread_t		thread_philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_lyceum		*lyceum;
}					t_featherless_biped;

// Parsing
void				parsing(int argc, char **argv, t_lyceum *l);
bool				valid_argv(char **av);
void				getting_proper_args(char **argv, t_lyceum *l);
void				lyceum_starter(t_lyceum *l);

// Error and clean routine
void				error_argv_checker(void);
void				error_argv_amount(void);
void				error_exec_clean(void);
void				error_nbr_size(void);


// Utils
size_t				ft_strlen(const char *s);
long					ft_atol(char *str);

#endif
