/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:08:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/04 14:50:38 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ul_fork(t_phil *p, int fork)
{
	p->s->forks_i[fork] = FALSE;
	pthread_mutex_unlock(&p->s->forks[fork]);
	return (FALSE);
}

int	philo_fork(t_phil *p, int left_fork, int right_fork)
{
	pthread_mutex_lock(&p->s->forks[left_fork]);
	if (check_dead(p) || print(p, "has taken a fork"))
		return (ul_fork(p, left_fork));
	p->s->forks_i[left_fork] = TRUE;
	if (p->s->total_phil == 1)
		return (ul_fork(p, left_fork));
	pthread_mutex_lock(&p->s->forks[right_fork]);
	if (check_dead(p) || print(p, "has taken a fork"))
		return (ul_fork(p, left_fork) || ul_fork(p, right_fork));
	p->s->forks_i[right_fork] = TRUE;
	return (TRUE);
}

int	philo_eating(t_phil *p, int left_fork, int right_fork)
{
	if (check_dead(p) || print(p, "is eating"))
		return (ul_fork(p, left_fork) || ul_fork(p, right_fork));
	pthread_mutex_lock(&p->s->m_last_meal);
	p->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&p->s->m_last_meal);
	sleep_in_ms(p->s->time_to_eat);
	ul_fork(p, left_fork);
	ul_fork(p, right_fork);
	count_eating(p);
	return (TRUE);
}

void	philo_loop(t_phil *p, int left_fork, int right_fork)
{
	while (!check_dead(p))
	{
		if (!philo_fork(p, left_fork, right_fork))
			break ;
		if (!philo_eating(p, left_fork, right_fork))
			break ;
		if (!check_dead(p))
		{
			print(p, "is sleeping");
			sleep_in_ms(p->s->time_to_sleep);
		}
		if (!check_dead(p))
			print(p, "is thinking");
		usleep(1);
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
		usleep(p->s->time_to_eat);
	left_fork = p->phil_num;
	total_phil = p->s->total_phil;
	right_fork = (p->phil_num + 1) % total_phil;
	philo_loop(p, left_fork, right_fork);
	return (NULL);
}
