/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philophers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarques <smarques@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 20:24:31 by smarques          #+#    #+#             */
/*   Updated: 2026/04/07 00:11:15 by smarques         ###   ########.fr       */
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
						// pthread_mutex_lock, pthread_mutex_unlock
typedef struct s_lyceum
{
}		t_lyceum;

typedef struct s_featherless_biped
{
}		t_featherless_biped;

// Parsing
bool	valid_argv(char **av);

// Error and clean routine
void	error_argv_checker(void);

// Utils
size_t	ft_strlen(const char *s);

#endif
