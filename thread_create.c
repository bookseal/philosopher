/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegichan <leegichan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:00:53 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 03:45:39 by leegichan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_phil	**create_phil_arr(t_status **status)
{
	t_phil		**phil_arr;
	int			i;
	t_status	*s;

	s = *status;
	s->start = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	s->last_meal = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	s->phil_threads = (pthread_t *)ft_calloc(s->total_phil + 1, sizeof(pthread_t));
	s->forks = ft_calloc(s->total_phil, sizeof(pthread_mutex_t));
	s->is_finish = (bool *)ft_calloc(s->total_phil, sizeof(bool));
	phil_arr = (t_phil **)ft_calloc(s->total_phil, sizeof(t_phil *));
	i = 0;
	while (i < s->total_phil)
	{
		phil_arr[i] = (t_phil *)ft_calloc(1, sizeof(t_phil));
		phil_arr[i]->phil_num = i;
		phil_arr[i]->s = s;
		i++;
	}
	return (phil_arr);
}

void	thread_create(t_status **status)
{
	t_phil		**phil_arr;
	t_status	*s;
	int			i;
	
	phil_arr = create_phil_arr(status);
	s = *status;
	i = 0;
	while (i < s->total_phil)
	{
		s->start[i] = get_time_in_ms();
		s->last_meal[i] = s->start[i];
		pthread_mutex_init(&(s->forks[i]), NULL);
		pthread_create(&s->phil_threads[i], NULL, philo, phil_arr[i]);
		i++;
	}
	pthread_create(&(s->phil_threads[s->total_phil]), NULL, monitor, s);
}
