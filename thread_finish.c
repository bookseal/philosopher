/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:03:22 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/24 17:23:32 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_all(t_status *s, t_phil **phil_arr)
{
	int	i;

	free(s->phil_threads);
	free(s->forks);
	free(s->forks_i);
	i = 0;
	while (i < s->total_phil)
	{
		free(phil_arr[i]);
		i++;
	}
	free(s);
}

void	thread_finish(t_phil **phil_arr)
{
	int			phil_num;
	pthread_t	*monitor_thread;
	t_status	*s;

	s = phil_arr[0]->s;
	phil_num = s->total_phil;
	monitor_thread = &(s->phil_threads[phil_num]);
	pthread_join(*monitor_thread, NULL);
	while (phil_num--)
	{
		pthread_join(s->phil_threads[phil_num], NULL);
		pthread_mutex_destroy(&s->forks[phil_num]);
	}
	pthread_mutex_destroy(&s->m_dead);
	pthread_mutex_destroy(&s->m_last_meal);
	pthread_mutex_destroy(&s->m_print);
	pthread_mutex_destroy(&s->m_finished_phil);
	free_all(s, phil_arr);
	return ;
}
