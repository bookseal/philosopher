/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:59:50 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/01 15:41:31 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	finish_phil(t_phil *p)
{
	p->count_eat++;
	pthread_mutex_lock(&p->s->m_finished_phil);
	if (p->s->is_limit && p->count_eat == p->s->num_must_eat)
	{
		p->s->finished_phil++;
		pthread_mutex_unlock(&p->s->m_finished_phil);
		return (TRUE);
	}
	pthread_mutex_unlock(&p->s->m_finished_phil);
	return (FALSE);
}

int	check_dead(t_phil *p)
{
	pthread_mutex_lock(&p->s->m_dead);
	if (p->s->is_dead == TRUE)
	{
		pthread_mutex_unlock(&p->s->m_dead);
		return (TRUE);
	}
	pthread_mutex_unlock(&p->s->m_dead);
	return (FALSE);
}
