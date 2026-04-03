/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-abre <ide-abre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:01:39 by ide-abre          #+#    #+#             */
/*   Updated: 2026/02/22 01:01:12 by ide-abre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_settings	t_settings;

typedef struct s_fork
{
	int						id;
	pthread_mutex_t			mutex;
}							t_fork;

typedef struct s_philo
{
	int						id;
	int						status;
	pthread_mutex_t			status_mtx;
	int						meals_eaten;
	pthread_mutex_t			meals_eaten_mtx;
	unsigned long			last_meal;
	pthread_mutex_t			last_meal_mtx;
	t_fork					*right_hand;
	t_fork					*left_hand;
	pthread_t				thread;
	t_fork					*forks;
	t_settings				*settings;
}							t_philo;

typedef enum e_status
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD,
	FULL,
	HAS_FORK,
}							t_status;

typedef struct s_settings
{
	int						num_philo;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						num_required_meals;
	int						all_threads_created;
	pthread_mutex_t			all_threads_mtx;
	int						stop_simulation;
	pthread_mutex_t			stop_mtx;
	pthread_mutex_t			printf_mutex;
	unsigned long			started;
	pthread_mutex_t			started_mtx;
}							t_settings;

typedef struct s_data
{
	t_settings				settings;
	t_philo					*philos;
	int						all_threads_created;
}							t_data;

/* Get and Set */
void						better_usleep(long milis, t_settings *set);
t_fork						*create_forks(t_settings *settings);
t_philo						*create_philo(t_settings *set, t_fork *forks);
long						ft_atol(const char *str);
int							ft_isdigit(int c);
int							ft_isspace(int c);
int							ft_mod(int x, int N);
int							ft_strlen(char *s);
void						set_long_mtx(pthread_mutex_t *mtx,
								unsigned long *target, unsigned long value);
unsigned long				get_long_mtx(pthread_mutex_t *mtx,
								unsigned long *value);
void						set_int_mtx(pthread_mutex_t *mtx, int *target,
								int value);
int							get_int_mtx(pthread_mutex_t *mtx, int *value);
long						get_current_time(void);
int							check_stop_condition(t_settings *set);
void						*restaurant_manager(void *arg);
int							ft_isdigit_string(char *s);
int							get_param(int argc, char **argv,
								t_settings *settings);
t_settings					set_settings(int argc, char **argv);
void						*start_philo(void *arg);
int							start_simulation(t_settings *settings,
								t_philo *philos);
void						eating(t_philo *philo);
void						sleeping(t_philo *philo);
void						thinking(t_philo *philo);
void						write_log(t_philo *philo);
void						clean(t_settings *settings, t_philo *philos,
								t_fork *forks);
#endif