/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:08:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/21 21:26:42 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

bool	is_finish(int *nb_of_times_eaten, t_phil *p)
{
	*nb_of_times_eaten += 1;
	if (*nb_of_times_eaten == p->s->num_must_eat)
	{
		// p->is_finish[p->phil_num] = true;
		return (true);
	}
	return (false);
}

void	philo_eating(t_phil *p, int left_fork, int right_fork)
{
	pthread_mutex_lock(&p->s->forks[left_fork]);
	print(p, "has taken a fork");
	pthread_mutex_lock(&p->s->forks[right_fork]);
	print(p, "has taken a fork");
	p->last_meal = get_time_in_ms();
	print(p, "is eating");
	sleep_in_ms(p->s->time_to_eat);
	pthread_mutex_unlock(&p->s->forks[left_fork]);
	pthread_mutex_unlock(&p->s->forks[right_fork]);
}

void	philo_loop(t_phil *p, int left_fork, int right_fork)
{
	int			nb_of_times_eaten;

	nb_of_times_eaten = 0;
	while (1)
	{
		philo_eating(p, left_fork, right_fork);
		print(p, "is sleeping");
		if (p->s->is_died)
			return ;
		sleep_in_ms(p->s->time_to_sleep);
		if (p->s->is_died)
			return ;
		print(p, "is thinking");
		if (is_finish(&nb_of_times_eaten, p))
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
	if (total_phil == 1)
	{
		print(p, "has taken a fork");
		return (NULL);
	}
	right_fork = (p->phil_num + 1) % total_phil;
	philo_loop(p, left_fork, right_fork);
	return (NULL);
}
