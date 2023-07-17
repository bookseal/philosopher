/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gichlee <gichlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:58:47 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/17 17:11:47 by gichlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	// t_phil		*phil_arr;
	t_status	*status;

	status = parsing(argc, argv);
	// phil_arr = init(&status);
	thread_create(&status);
	// thread_finish(status);
	exit(0);
}
