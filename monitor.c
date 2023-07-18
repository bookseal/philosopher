/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegichan <leegichan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:52 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 04:00:36 by leegichan        ###   ########.fr       */
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
		if (s->is_finish[phil_num])
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

	s = (t_status *)ptr;
	while (1)
	{
		idx = 0;
		while (idx < s->total_phil)
		{
			current_ms = get_time_in_ms();
			if (current_ms - s->last_meal[idx] > (size_t)s->time_to_die)
			{
				print(current_ms, s->start, idx, "died");
				exit(1);
			}
			idx++;
		}
		is_finish_all(s);
		usleep(10);
	}
	return (NULL);
}
