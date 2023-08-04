/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:52 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/04 14:32:35 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	is_finished_phil_same_total_phil(t_phil **phil_arr)
{
	t_status	*s;

	s = phil_arr[0]->s;
	pthread_mutex_lock(&s->m_finished_phil);
	if (s->is_limit && s->finished_phil == s->total_phil)
	{
		pthread_mutex_unlock(&s->m_finished_phil);
		pthread_mutex_lock(&s->m_dead);
		s->is_dead = TRUE;
		pthread_mutex_unlock(&s->m_dead);
		return (TRUE);
	}
	pthread_mutex_unlock(&s->m_finished_phil);
	return (FALSE);
}

int	is_one_dead(t_phil **phil_arr)
{
	t_status	*s;
	int			idx;
	size_t		t_die;

	s = phil_arr[0]->s;
	t_die = (size_t)s->time_to_die;
	idx = 0;
	while (idx < s->total_phil)
	{
		pthread_mutex_lock(&s->m_last_meal);
		if (get_time_in_ms() > phil_arr[idx]->last_meal + t_die)
		{
			pthread_mutex_unlock(&s->m_last_meal);
			pthread_mutex_lock(&s->m_dead);
			s->is_dead = TRUE;
			pthread_mutex_unlock(&s->m_dead);
			print_dead(phil_arr[idx]);
			return (TRUE);
		}
		pthread_mutex_unlock(&s->m_last_meal);
		idx++;
	}
	return (FALSE);
}

void	*monitor(void *ptr)
{
	t_phil		**phil_arr;

	phil_arr = (t_phil **)ptr;
	while (1)
	{
		pthread_mutex_lock(&phil_arr[0]->s->m_dead);
		if (phil_arr[0]->s->is_dead == TRUE)
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
