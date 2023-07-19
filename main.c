/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:58:47 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 18:08:18 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_status	*status;
	t_phil		**phil_arr;

	status = parsing(argc, argv);
	phil_arr = thread_create(&status);
	thread_finish(status, phil_arr);
	exit(0);
}
