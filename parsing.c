/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:21:20 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/22 19:59:26 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_status	*parsing_error_free(char *msg, int *argv_int, t_status *status)
{
	printf("%s\n", msg);
	if (argv_int)
		free(argv_int);
	if (status)
		free(status);
	return (0);
}

t_status	*create_status(int *argv_int, int argc)
{
	t_status	*status;

	status = (t_status *)ft_calloc(1, sizeof(t_status));
	if (!status)
		return (parsing_error_free("malloc failed", argv_int, 0));
	status->total_phil = argv_int[1];
	if (status->total_phil < 1)
		return (parsing_error_free("invalid first argument", argv_int, status));
	status->time_to_die = argv_int[2];
	status->time_to_eat = argv_int[3];
	status->time_to_sleep = argv_int[4];
	if (argc == 6)
	{
		status->is_limit = true;
		status->num_must_eat = argv_int[5];
	}
	if (argc == 6 && status->num_must_eat == 0)
		return (parsing_error_free("invalid fifth argument", argv_int, status));
	return (status);
}

t_status	*parsing(int argc, char **argv)
{
	int			*argv_int;
	t_status	*status;
	int			idx;

	if (argc < 5 || argc > 6)
		return (parsing_error_free("invalid argumets", 0, 0));
	argv_int = (int *)ft_calloc(argc, sizeof(int));
	if (!argv_int)
		return (parsing_error_free("malloc failed", 0, 0));
	idx = 1;
	while (argv[idx] != NULL)
	{
		argv_int[idx] = ft_atoi(argv[idx]);
		if (argv_int[idx] < 0)
			return (parsing_error_free("only positive numbers", argv_int, 0));
		idx++;
	}
	status = create_status(argv_int, argc);
	if (!status)
		return (0);
	else
		free(argv_int);
	return (status);
}
