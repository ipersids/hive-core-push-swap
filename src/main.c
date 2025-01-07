/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:50:25 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 15:46:44 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data data;

	ps_data_init(&data);
	ps_get_numbers(argc, argv, &data.input.num, &data.input.len);
	if (!data.input.num)
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	if (ps_sorted_ascending(data.input.num, data.input.len))
		ps_destroy_data_exit(&data, EXIT_SUCCESS);
	if (!ps_stacks_init(&data))
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	ft_printf("Success\n");
	ps_destroy_data_exit(&data, EXIT_SUCCESS);
}
