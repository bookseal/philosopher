/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:52 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 16:35:33 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	is_finish_all(t_status *s)
{
	int	done;
	int	phil_num;

	done = 0;
	phil_num = s->total_phil;
	while (phil_num--)
	{
		if (s->is_finish)
			done++;
	}
	if (done == s->total_phil)
		exit(0);
}

void	*monitor(void *ptr)
{
	t_status	*s;
	size_t		current_ms;
	int			idx;
	int			phil_num;

	usleep(100);
	s = (t_status *)ptr;
	while (1)
	{
		phil_num = s->total_phil;
		while (phil_num--)
		{
			current_ms = get_time_in_ms();
			if (current_ms - s->last_meal[phil_num] > s->time_to_die)
			{
				print(current_ms, s->start, phil_num, "died");
				exit(1);
			}
		}
		is_finish_all(s);
		usleep(100);
	}
	return (NULL);
}
