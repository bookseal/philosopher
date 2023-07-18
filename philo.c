/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegichan <leegichan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:08:12 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 04:01:16 by leegichan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print(size_t time, size_t *start, int phil_num, char *message)
{
	size_t	current_ms_from_start;

	current_ms_from_start = time - start[phil_num];
	printf("%zd %d %s\n", current_ms_from_start, phil_num, message);
}

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

void	philo_loop(t_phil *p, int left_fork, int right_fork)
{
	int			nb_of_times_eaten;

	nb_of_times_eaten = 0;
	while (1)
	{
		pthread_mutex_lock(&p->s->forks[left_fork]);
		pthread_mutex_lock(&p->s->forks[right_fork]);
		print(get_time_in_ms(), p->s->start, p->phil_num, "has taken a fork");
		print(get_time_in_ms(), p->s->start, p->phil_num, "has taken a fork");
		usleep(10);
		print(get_time_in_ms(), p->s->start, p->phil_num, "is eating");
		sleep_in_ms(p->s->time_to_eat);
		p->s->last_meal[p->phil_num] = get_time_in_ms();
		pthread_mutex_unlock(&p->s->forks[left_fork]);
		pthread_mutex_unlock(&p->s->forks[right_fork]);
		print(get_time_in_ms(), p->s->start, p->phil_num, "is sleeping");
		sleep_in_ms(p->s->time_to_sleep);
		print(get_time_in_ms(), p->s->start, p->phil_num, "is thinking");
		if (is_finish(&nb_of_times_eaten, p))
			break ;
	}
}

void	*philo(void *ptr)
{
	t_phil	*p;
	int		left_fork;
	int		right_fork;
	int		total_phil;

	p = (t_phil *)ptr;
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
		usleep(100);
	philo_loop(p, left_fork, right_fork);
	return (NULL);
}
