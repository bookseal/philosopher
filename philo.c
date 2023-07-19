/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:08:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 18:29:41 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	swap_forks_if_needed(int *left_fork, int *right_fork)
{
	int	temp;

	if (*right_fork < *left_fork)
	{
		temp = *right_fork;
		*right_fork = *left_fork;
		*left_fork = temp;
	}
}

bool	is_finish(int *nb_of_times_eaten, t_phil *p)
{
	*nb_of_times_eaten += 1;
	if (*nb_of_times_eaten == p->s->num_must_eat)
	{
		p->s->is_finish[p->phil_num] = true;
		return (true);
	}
	return (false);
}

void	philo_eating(t_phil *p, int left_fork, int right_fork)
{
	pthread_mutex_lock(&p->s->forks[left_fork]);
	pthread_mutex_lock(&p->s->forks[right_fork]);
	print(get_time_in_ms(), p->s->start, p->phil_num, "has taken a fork");
	print(get_time_in_ms(), p->s->start, p->phil_num, "has taken a fork");
	print(get_time_in_ms(), p->s->start, p->phil_num, "is eating");
	p->s->last_meal[p->phil_num] = get_time_in_ms() + p->s->time_to_eat;
	sleep_in_ms(p->s->time_to_eat);
	if (p->s->is_died)
		return ;
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
		print(get_time_in_ms(), p->s->start, p->phil_num, "is sleeping");
		if (p->s->is_died)
			return ;
		sleep_in_ms(p->s->time_to_sleep);
		if (p->s->is_died)
			return ;
		print(get_time_in_ms(), p->s->start, p->phil_num, "is thinking");
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
		usleep(0);
	left_fork = p->phil_num;
	total_phil = p->s->total_phil;
	if (total_phil == 1)
	{
		print(get_time_in_ms(), p->s->start, p->phil_num, "has taken a fork");
		return (NULL);
	}
	right_fork = (p->phil_num + 1) % total_phil;
	swap_forks_if_needed(&left_fork, &right_fork);
	if (p->phil_num % 2 == 1)
		usleep(10);
	philo_loop(p, left_fork, right_fork);
	return (NULL);
}
