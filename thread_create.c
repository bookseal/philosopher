/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:00:53 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/27 17:04:21 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	create_phil_threads(t_phil **phil_arr)
{
	int			i;
	t_status	*s;
	size_t		time;

	time = get_time_in_ms();
	s = phil_arr[0]->s;
	i = 0;
	while (i < s->total_phil)
	{
		phil_arr[i]->last_meal = time;
		phil_arr[i]->start = time;
		pthread_create(&s->phil_threads[i], NULL, philo, phil_arr[i]);
		usleep(1);
		i ++;
	}
}

void	init_mutex(t_status *s)
{
	int	i;

	i = 0;
	while (i < s->total_phil)
	{
		pthread_mutex_init(&(s->forks[i]), NULL);
		i++;
	}
	pthread_mutex_init(&s->m_print, NULL);
	pthread_mutex_init(&s->m_dead, NULL);
	pthread_mutex_init(&s->m_last_meal, NULL);
	pthread_mutex_init(&s->m_finished_phil, NULL);
}

void	thread_create(t_phil **phil_arr)
{
	int			total;
	t_status	*s;

	s = phil_arr[0]->s;
	total = s->total_phil;
	init_mutex(s);
	create_phil_threads(phil_arr);
	usleep(100);
	pthread_create(&(s->phil_threads[total]), NULL, monitor, phil_arr);
	return ;
}
