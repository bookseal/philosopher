/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:58:47 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/24 16:53:08 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_status	*status;
	t_phil		**phil_arr;

	status = parsing(argc, argv);
	if (!status)
		return (0);
	phil_arr = malloc_phil_arr(&status);
	if (!phil_arr)
		return (0);
	thread_create(phil_arr);
	thread_finish(phil_arr);
	return (0);
}
