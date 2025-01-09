/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:50:25 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 22:25:05 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_partition	part;

	if (1 == argc)
		return (0);
	ps_data_init(&data, FALSE);
	if (!ps_get_numbers(argc, argv, &data.input.num, &data.input.len))
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	if (ps_sorted_ascending(data.input.num, data.input.len))
		ps_destroy_data_exit(&data, EXIT_SUCCESS);
	if (!ps_stacks_init(&data))
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	part.loc = HEAD_A;
	part.size = data.a.size;
	ps_choose_sort(&data, &part);
	ps_print_commands(&data.command);
	ps_destroy_data_exit(&data, EXIT_SUCCESS);
}
