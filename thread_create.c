/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:00:53 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/21 21:28:07 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	get_time_and_create_thread(t_status *s, t_phil **phil_arr, int i)
{
	size_t	time;

	time = get_time_in_ms();
	phil_arr[i]->last_meal = time;
	phil_arr[i]->start = time;
	pthread_create(&s->phil_threads[i], NULL, philo, phil_arr[i]);
}

void	create_even_and_odd(t_phil **phil_arr)
{
	int			i;
	t_status	*s;

	s = phil_arr[0]->s;
	i = 0;
	while (i < s->total_phil)
	{
		get_time_and_create_thread(s, phil_arr, i);
		i += 2;
	}
	usleep(phil_arr[0]->s->time_to_eat / 5);
	i = 1;
	while (i < s->total_phil)
	{
		get_time_and_create_thread(s, phil_arr, i);
		i += 2;
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
	// TODO: other mutex lock
}

void	thread_create(t_phil **phil_arr)
{
	int			total;
	t_status	*s;

	s = phil_arr[0]->s;
	total = s->total_phil;
	init_mutex(s);
	create_even_and_odd(phil_arr);
	// pthread_create(&(s->phil_threads[total]), NULL, monitor, phil_arr);
	return ;
}
