/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:49:42 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/21 21:17:19 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"


void	print(t_phil *p, char *msg)
{
	size_t	time;
	size_t	current_ms_from_start;

	time = get_time_in_ms();
	current_ms_from_start = time - p->start;
	printf("%zd %d %s\n", current_ms_from_start, p->phil_num, msg);
	if (ft_strncmp(msg, "died", ft_strlen("died")) == 0)
		exit(0);
}
