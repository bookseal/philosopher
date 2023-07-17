/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:21:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 14:36:29 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_status	*parsing(int argc, char **argv)
{
	int			*argv_int;
	t_status	*status;
	int			idx;

	if (argc < 5 || argc > 6)
		exit(1);
	argv_int = (int *)ft_calloc(argc, sizeof(int));
	idx = 1;
	while (argv[idx] != NULL)
	{
		argv_int[idx] = ft_atoi(argv[idx]);
		idx++;
	}
	if (argv_int[1] < 1)
	{
		printf("number of philosopher must be over 1.\n");
		exit(1);
	}
	status = (t_status *)ft_calloc(1, sizeof(t_status *));
	status->total_phil = argv_int[1];
	status->time_to_die = argv_int[2];
	status->time_to_eat = argv_int[3];
	status->time_to_sleep = argv_int[4];
	if (argc == 6)
		status->num_must_eat = argv_int[5];
	return (status);
}
