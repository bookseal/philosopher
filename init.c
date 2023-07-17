/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:24:03 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 17:08:40 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_phil	*init(t_status **status)
{
	t_phil		*phil_arr;
	int			phil_num;
	t_status	*s;

	s = *status;
	// s->start = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	// s->last_meal = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	// s->phil_threads = ft_calloc(s->total_phil + 1, sizeof(pthread_t));
	s->forks = ft_calloc(s->total_phil, sizeof(pthread_mutex_t));
	s->is_finish = (bool *)ft_calloc(s->total_phil, sizeof(bool));
	phil_arr = (t_phil *)ft_calloc(s->total_phil, sizeof(t_phil));
	phil_num = s->total_phil;
	while (phil_num--)
	{
		phil_arr[phil_num].phil_num = phil_num;
		phil_arr[phil_num].s = s;
	}
	return (phil_arr);
}
