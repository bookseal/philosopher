/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:12:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/01 11:57:29 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	get_time_in_ms(void)
{
	struct timeval	time;
	size_t			time_ms;

	gettimeofday(&time, NULL);
	time_ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time_ms);
}

void	sleep_in_ms(int sleep_ms)
{
	size_t	start_ms;

	start_ms = get_time_in_ms();
	while (get_time_in_ms() - start_ms < (size_t)sleep_ms)
		usleep(100);
}
