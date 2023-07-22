/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:52 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/22 20:53:07 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_finished_phil_same_total_phil(t_phil **phil_arr)
{
	t_status	*s;

	s = phil_arr[0]->s;
	pthread_mutex_lock(&s->m_finished_phil);
	if (s->finished_phil == s->total_phil)
	{
		pthread_mutex_unlock(&s->m_finished_phil);
		return (true);
	}
	pthread_mutex_unlock(&s->m_finished_phil);
	return (false);
}

bool	is_one_dead(t_phil **phil_arr)
{
	t_status	*s;
	int			idx;
	size_t		last_meal;
	size_t		t_die;

	s = phil_arr[0]->s;
	idx = 0;
	while (idx < s->total_phil)
	{
		pthread_mutex_lock(&s->m_last_meal);
		last_meal = phil_arr[idx]->last_meal;
		pthread_mutex_unlock(&s->m_last_meal);
		t_die = (size_t)s->time_to_die;
		if (get_time_in_ms() > last_meal + t_die)
		{
			pthread_mutex_lock(&s->m_dead);
			s->is_dead = true;
			pthread_mutex_unlock(&s->m_dead);
			print(phil_arr[idx], "died");
			return (true);
		}
		idx++;
	}
	return (false);
}

void	*monitor(void *ptr)
{
	t_phil		**phil_arr;

	phil_arr = (t_phil **)ptr;
	while (1)
	{
		pthread_mutex_lock(&phil_arr[0]->s->m_dead);
		if (phil_arr[0]->s->is_dead == true)
		{
			pthread_mutex_unlock(&phil_arr[0]->s->m_dead);
			return (NULL);
		}
		pthread_mutex_unlock(&phil_arr[0]->s->m_dead);
		if (is_finished_phil_same_total_phil(phil_arr))
			return (NULL);
		if (is_one_dead(phil_arr))
			return (NULL);
		usleep(10);
	}
	return (NULL);
}
