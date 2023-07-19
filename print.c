/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:49:42 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 18:10:31 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print(size_t time, size_t *start, int phil_num, char *message)
{
	size_t	current_ms_from_start;

	current_ms_from_start = time - start[phil_num];
	printf("%zd %d %s\n", current_ms_from_start, phil_num, message);
	if (ft_strncmp(message, "died", ft_strlen("died")) == 0)
		exit(0);
}
