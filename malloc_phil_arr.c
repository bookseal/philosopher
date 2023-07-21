/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_phil_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:31:13 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/21 20:55:32 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_phil	**malloc_phil_arr(t_status **status)
{
	t_phil		**phil_arr;
	int			i;
	t_status	*s;

	s = *status;
	s->phil_threads = ft_calloc(s->total_phil + 1, sizeof(pthread_t));
	s->forks = ft_calloc(s->total_phil, sizeof(pthread_mutex_t));
	// s->start = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	// s->last_meal = (size_t *)ft_calloc(s->total_phil, sizeof(size_t));
	// s->is_finish = (bool *)ft_calloc(s->total_phil, sizeof(bool));
	phil_arr = (t_phil **)ft_calloc(s->total_phil, sizeof(t_phil *));
	if (!phil_arr)
		;
	i = 0;
	while (i < s->total_phil)
	{
		phil_arr[i] = (t_phil *)ft_calloc(1, sizeof(t_phil));
		if (!phil_arr[i])
			;
		phil_arr[i]->phil_num = i;
		phil_arr[i]->s = s;
		i++;
	}
	return (phil_arr);
}
