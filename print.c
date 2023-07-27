/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:49:42 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/27 17:02:02 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print(size_t time, t_phil *p, char *msg)
{
	size_t	current_ms_from_start;

	pthread_mutex_lock(&(p->s->m_print));
	current_ms_from_start = time - p->start;
	printf("%zd %d %s\n", current_ms_from_start, p->phil_num, msg);
	pthread_mutex_unlock(&(p->s->m_print));
}
