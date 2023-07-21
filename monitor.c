/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:19:52 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/21 20:19:30 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// FIXME: do not die
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
	t_phil		**phil_arr;
	t_status	*s;
	int			idx;

	phil_arr = (t_phil **)ptr;
	s = phil_arr[0]->s;
	while (1)
	{
		idx = 0;
		while (idx < s->total_phil)
		{
			if (get_time_in_ms() > s->last_meal[idx] + (size_t)s->time_to_die)
			{
				print(get_time_in_ms(), s->start, idx, "died");
				s->is_died = true;
				thread_finish(s, phil_arr);
			}
			idx++;
		}
		is_finish_all(s);
		usleep(10);
	}
	return (NULL);
}
