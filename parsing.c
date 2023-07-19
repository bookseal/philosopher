/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:21:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 16:45:32 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_status	*create_status(int *argv_int, int argc)
{
	t_status	*status;

	status = (t_status *)ft_calloc(1, sizeof(t_status));
	if (!status)
		exit(1);
	status->total_phil = argv_int[1];
	status->time_to_die = argv_int[2];
	status->time_to_eat = argv_int[3];
	status->time_to_sleep = argv_int[4];
	if (argc == 6)
	{
		if (argv_int[5] == 0)
		{
			free(status);
			free(argv_int);
			exit(0);
		}
		status->num_must_eat = argv_int[5];
	}
	return (status);
}

t_status	*parsing(int argc, char **argv)
{
	int			*argv_int;
	t_status	*status;
	int			idx;

	if (argc < 5 || argc > 6)
		exit(1);
	argv_int = (int *)ft_calloc(argc, sizeof(int));
	if (!argv_int)
		exit(1);
	idx = 1;
	while (argv[idx] != NULL)
	{
		argv_int[idx] = ft_atoi(argv[idx]);
		idx++;
	}
	if (argv_int[1] < 1)
	{
		printf("number of philosopher must be over 1.\n");
		free(argv_int);
		exit(1);
	}
	status = create_status(argv_int, argc);
	free(argv_int);
	return (status);
}
