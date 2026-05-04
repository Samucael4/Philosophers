/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:24:31 by smarques          #+#    #+#             */
/*   Updated: 2026/05/04 22:28:12 by smarques         ###   ########.fr       */
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

typedef struct s_start_line
{
	pthread_mutex_t	mutex_start_line;
	bool			all_set;
}					t_start_line;

typedef struct s_lyceum
{
	long			nbr_philos;
	long			nbr_forks;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			amount_times_eat;
	long			starting_time;
	int				i;
	pthread_mutex_t	*mutex_fork;
	pthread_mutex_t	mutex_printf;
	pthread_mutex_t	mutex_thanatos;
	pthread_mutex_t	mutex_amount_meal;
	bool			thread_cut_by_atropos;
	bool			satisfied;
	t_start_line	sl;
}					t_lyceum;

typedef struct s_featherless_biped
{
	int				id;
	t_lyceum		*knowledge;
	pthread_t		thread_philo;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long			last_time_eaten;
	long			amount_meals;
}					t_featherless_biped;

// Parsing
void				parsing(int argc, char **argv, t_lyceum *l);

// Preparation
void				getting_ready_to_feast(t_featherless_biped **p,
						t_lyceum *l);

// Error msgs and clean routine
void				error_msg(char *str);
void				clean_after_philos(t_lyceum *l);
void				mutex_cleaner(t_lyceum *l, int amount);
void				clean_all(t_featherless_biped *p, t_lyceum *l);
void				clean_after_mutex(t_lyceum *l, int fail_index);

// Utils
long				kronos_now(void);
long				ft_atol(char *str);
size_t				ft_strlen(const char *s);
bool				mini_sleeps(t_lyceum *l, long start_action,
						long time_action);

// Movements
void				get_fork_mov(t_featherless_biped *p);
void				sleep_mov(t_featherless_biped *p);
void				think_mov(t_featherless_biped *p);
void				eat_mov(t_featherless_biped *p);

// Helpers main
bool				end_simulation_verification(t_lyceum *l,
						t_featherless_biped *p);
bool				argos_core_loop(t_lyceum *l, t_featherless_biped *p);
void				wraper_threads_join(t_lyceum *l, t_featherless_biped *p);
void				safe_threads_create(int status, t_lyceum *l,
						t_featherless_biped *p);
int					wraper_threads_create(t_lyceum *l, t_featherless_biped *p);

// Routine and helpers and utils
bool				am_i_full(t_featherless_biped *p);
bool				life_checker(t_featherless_biped *p);
bool				wait_all_start(t_featherless_biped *p);
bool				forks_order_grab(t_featherless_biped *p);
bool				routine_core_loop(t_featherless_biped *p);
bool				eating_release_forks(t_featherless_biped *p);
void				enven_order_grab(t_featherless_biped *p);
void				think_a_little(t_featherless_biped *p);
void				odd_order_grab(t_featherless_biped *p);
void				taking_notes(t_featherless_biped *p);
void				*routine_of_philo(void *args);

#endif