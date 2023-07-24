/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:08:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/24 17:59:40 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	philo_fork(t_phil *p, int left_fork, int right_fork)
{
	pthread_mutex_lock(&p->s->forks[left_fork]);
	if (check_dead(p))
		return (false);
	print(get_time_in_ms(), p, "has taken a fork");
	p->s->forks_i[left_fork] = true;
	if (p->s->total_phil == 1)
	{
		pthread_mutex_unlock(&p->s->forks[left_fork]);
		return (false);
	}
	pthread_mutex_lock(&p->s->forks[right_fork]);
	if (check_dead(p))
		return (false);
	print(get_time_in_ms(), p, "has taken a fork");
	p->s->forks_i[right_fork] = true;
	pthread_mutex_lock(&p->s->m_last_meal);
	p->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&p->s->m_last_meal);
	return (true);
}

bool	philo_eating(t_phil *p, int left_fork, int right_fork)
{
	if (check_dead(p))
		return (false);
	print(get_time_in_ms(), p, "is eating");
	sleep_in_ms(p->s->time_to_eat);
	p->s->forks_i[left_fork] = false;
	pthread_mutex_unlock(&p->s->forks[left_fork]);
	p->s->forks_i[right_fork] = false;
	pthread_mutex_unlock(&p->s->forks[right_fork]);
	if (finish_phil(p))
		return (false);
	return (true);
}

void	philo_loop(t_phil *p, int left_fork, int right_fork)
{
	while (!check_dead(p))
	{
		if (check_dead(p) || !philo_fork(p, left_fork, right_fork))
			break ;
		if (check_dead(p) || !philo_eating(p, left_fork, right_fork))
			break ;
		if (!check_dead(p))
		{
			print(get_time_in_ms(), p, "is sleeping");
			sleep_in_ms(p->s->time_to_sleep);
		}
		if (!check_dead(p))
			print(get_time_in_ms(), p, "is thinking");
		if (check_dead(p))
			break ;
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
	right_fork = (p->phil_num + 1) % total_phil;
	philo_loop(p, left_fork, right_fork);
	return (NULL);
}
