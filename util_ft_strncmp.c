/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 17:03:25 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 18:16:14 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	ch1;
	unsigned char	ch2;
	size_t			idx;

	if (n == 0)
		return (0);
	idx = 0;
	while (1)
	{		
		ch1 = (unsigned char)s1[idx];
		ch2 = (unsigned char)s2[idx];
		if (ch1 != ch2 || ch1 == '\0' || ch2 == '\0' || idx + 1 == n)
			break ;
		idx++;
	}
	return (ch1 - ch2);
}
