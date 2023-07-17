/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:00:53 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 19:53:10 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	thread_create(t_status **status)
{
	t_phil		*phil_arr;
	int			phil_num;
	int			i;
	t_status	*s;

	s = *status;
	s->start = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	s->last_meal = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	s->phil_threads = ft_calloc(s->total_phil + 1, sizeof(pthread_t));
	s->forks = ft_calloc(s->total_phil, sizeof(pthread_mutex_t));
	s->is_finish = (bool *)ft_calloc(s->total_phil, sizeof(bool));
	phil_arr = (t_phil *)ft_calloc(s->total_phil, sizeof(t_phil));
	phil_num = s->total_phil;
	while (phil_num--)
	{
		phil_arr[phil_num].phil_num = phil_num;
		phil_arr[phil_num].s = s;
	}
	i = 0;
	while (i < s->total_phil)
	{
		s->start[i] = get_time_in_ms();
		s->last_meal[i] = s->start[i];
		pthread_mutex_init(&(s->forks[i]), NULL);
		printf("i = %d\n", i);
		pthread_create(&s->phil_threads[i], NULL, philo, &phil_arr[i]);
		i++;
	}
	// pthread_create(&(s->phil_threads[s->total_phil]), NULL, monitor, s);
}
