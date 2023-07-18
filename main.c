/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leegichan <leegichan@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:58:47 by gichlee           #+#    #+#             */
/*   Updated: 2023/07/19 03:46:08 by leegichan        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	t_status	*status;

	status = parsing(argc, argv);
	thread_create(&status);
	thread_finish(status);
	exit(0);
}
