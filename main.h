/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:17:57 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/27 21:46:32 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0

typedef struct s_status
{
	int				total_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	bool			is_limit;
	int				finished_phil;
	pthread_t		*phil_threads;
	pthread_mutex_t	*forks;
	int				*forks_i;
	bool			is_dead;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_last_meal;
	pthread_mutex_t	m_finished_phil;
}	t_status;

typedef struct s_phil
{
	int				phil_num;
	size_t			start;
	size_t			last_meal;
	int				count_eat;
	struct s_status	*s;
}	t_phil;

bool		finish_phil(t_phil *p);
bool		check_dead(t_phil *p);
t_phil		**malloc_phil_arr(t_status **status);
int			print(t_phil *p, char *msg);
void		sleep_in_ms(int sleep_ms);
void		thread_finish(t_phil **phil_arr);
void		*monitor(void *ptr);
void		thread_create(t_phil **phil_arr);
void		*philo(void *ptr);
t_status	*parsing(int argc, char **argv);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
size_t		get_time_in_ms(void);
#endif