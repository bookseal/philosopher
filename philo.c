/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:08:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/24 14:09:56 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	check_dead(t_phil *p)
{
	pthread_mutex_lock(&p->s->m_dead);
	if (p->s->is_dead == true)
	{
		pthread_mutex_unlock(&p->s->m_dead);
		return (true);
	}
	pthread_mutex_unlock(&p->s->m_dead);
	if (p->s->is_limit && p->count_eat == p->s->num_must_eat)
	{
		pthread_mutex_lock(&p->s->m_finished_phil);
		p->s->finished_phil++;
		pthread_mutex_unlock(&p->s->m_finished_phil);
		return (true);
	}
	return (false);
}

void	philo_eating(t_phil *p, int left_fork, int right_fork)
{
	pthread_mutex_lock(&p->s->forks[left_fork]);
	print(p, "has taken a fork");
	pthread_mutex_lock(&p->s->forks[right_fork]);
	if (check_dead(p))
		return ;
	print(p, "has taken a fork");
	pthread_mutex_lock(&p->s->m_last_meal);
	p->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&p->s->m_last_meal);
	if (check_dead(p))
		return ;
	print(p, "is eating");
	p->count_eat++;
	sleep_in_ms(p->s->time_to_eat);
	pthread_mutex_unlock(&p->s->forks[left_fork]);
	pthread_mutex_unlock(&p->s->forks[right_fork]);
}

void	philo_loop(t_phil *p, int left_fork, int right_fork)
{
	while (!check_dead(p))
	{
		philo_eating(p, left_fork, right_fork);
		if (check_dead(p))
			break ;
		print(p, "is sleeping");
		sleep_in_ms(p->s->time_to_sleep);
		if (check_dead(p))
			break ;
		print(p, "is thinking");
		usleep(10);
	}
}

void	*philo(void *ptr)
{
	t_phil	*p;
	int		left_fork;
	int		right_fork;
	int		total_phil;

	p = (t_phil *)ptr;
	if (p->phil_num % 2 == 1)
		usleep(10);
	left_fork = p->phil_num;
	total_phil = p->s->total_phil;
	while (total_phil == 1)
	{
		print(p, "has taken a fork");
		return (NULL);
	}
	right_fork = (p->phil_num + 1) % total_phil;
	philo_loop(p, left_fork, right_fork);
	return (NULL);
}
