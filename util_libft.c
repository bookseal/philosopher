/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:53:26 by gichlee           #+#    #+#             */
/*   Updated: 2023/08/02 19:53:31 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static size_t	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

static char	*atoa_removed_spaces_sign(char *str, int *sign)
{
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
			break ;
		else if (*str == '+')
		{
			str++;
			break ;
		}
		else if (*str == '-')
		{
			*sign = -1;
			str++;
			break ;
		}
		else if ((9 <= *str && *str <= 13) || *str == ' ')
			str++;
		else
			return (0);
	}
	return (str);
}

int	ft_atoi(const char *str)
{
	char				*num_str;
	int					s;
	unsigned long long	res[3];

	s = 1;
	num_str = atoa_removed_spaces_sign((char *)str, &s);
	if (num_str == 0 || *num_str == 0)
		return (0);
	res[0] = 0;
	res[1] = 0;
	while (*num_str != '\0')
	{
		if (!ft_isdigit(*num_str))
			return (0);
		res[0] = res[0] * 10 + (*num_str - '0');
		res[2] = res[0] / 10;
		res[2] -= (*num_str - '0') / 10;
		if (res[1] != res[2])
			return (0);
		res[1] = res[0];
		num_str++;
	}
	if ((s == 1 && res[0] > 2147483647) || (s == -1 && res[0] > 2147483648))
		return (0);
	return ((int)(s * res[0]));
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	if (n == 0)
		return ;
	else
	{
		idx = 0;
		while (idx < n)
		{
			((char *)s)[idx] = 0;
			idx++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
