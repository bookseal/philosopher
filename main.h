/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:17:57 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 16:22:05 by gichlee          ###   ########.fr       */
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

typedef struct s_status
{
	int				total_phil;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	size_t			*start;
	size_t			*last_meal;
	pthread_t		*phil_threads;
	pthread_mutex_t	*forks;
	bool			*is_finish;
}	t_status;

typedef struct s_phil
{
	int				phil_num;
	t_status		*s;
}	t_phil;

void		print(size_t time, size_t *start, int phil_num, char *message);
size_t		get_time_in_ms(void);
void		sleep_in_ms(int sleep_ms);
void		thread_finish(t_status *s);
void		*monitor(void *ptr);
void		thread_create(t_phil *phil_arr, t_status *status);
void		*philo(void *ptr);
t_phil		*init(t_status *status);
t_status	*parsing(int argc, char **argv);
int			ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);

#endif