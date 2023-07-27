/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:49:42 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/27 22:43:56 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	print(t_phil *p, char *msg)
{
	size_t	time;
	size_t	current_ms_from_start;

	pthread_mutex_lock(&(p->s->m_print));
	time = get_time_in_ms();
	current_ms_from_start = time - p->start;
	printf("%zd %d %s\n", current_ms_from_start, p->phil_num, msg);
	pthread_mutex_unlock(&(p->s->m_print));
	return (0);
}
