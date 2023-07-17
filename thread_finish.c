/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_finish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:03:22 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 16:21:51 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	thread_finish(t_status *s)
{
	int			phil_num;
	pthread_t	*monitor_thread;

	phil_num = s->total_phil;
	monitor_thread = &(s->phil_threads[phil_num]);
	pthread_join(*monitor_thread, NULL);
	while (phil_num--)
	{
		pthread_join(s->phil_threads[phil_num], NULL);
		pthread_mutex_destroy(&s->forks[phil_num]);
	}
}
