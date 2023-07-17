/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:00:53 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 16:28:10 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	thread_create(t_phil *phil_arr, t_status *s)
{
	int		i;

	i = s->total_phil;
	pthread_create(&(s->phil_threads[i]), NULL, monitor, s);
	while (i)
	{	
		i--;
		s->start[i] = get_time_in_ms();
		pthread_mutex_init(&(s->forks[i]), NULL);
		pthread_create(&s->phil_threads[i], NULL, philo, &phil_arr[i]);
	}
}
