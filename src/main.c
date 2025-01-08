/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:50:25 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 00:40:26 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void tmp_print_stack(t_queue *stack, char ch) {
// 	size_t indx;
// 	ft_printf("STACK '%c'\n", ch);
// 	ft_printf("Queue size = %d, ", (int)stack->size);
// 	ft_printf("current len = %d\n",(int)stack->len);
// 	for (size_t i = 0; i < stack->len; i++) {
// 		indx = (stack->read + i) % stack->size;
// 		ft_printf("%d , ", (int)stack->buf[indx], (int)i);
// 	}
// 	ft_printf("\n");
// }

int	main(int argc, char **argv)
{
	t_data 		data;
	t_partition	part;

	ps_data_init(&data);
	ps_get_numbers(argc, argv, &data.input.num, &data.input.len);
	if (!data.input.num)
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	if (ps_sorted_ascending(data.input.num, data.input.len))
		ps_destroy_data_exit(&data, EXIT_SUCCESS);
	if (!ps_stacks_init(&data))
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	part.loc = HEAD_A;
	part.size = data.a.size;
	ps_sort(&data, &part);
	ps_print_commands(&data.command);
	// ft_printf("\nFINAL!\n");
	// tmp_print_stack(&data.a, 'A');
	// tmp_print_stack(&data.b, 'B');
	ps_destroy_data_exit(&data, EXIT_SUCCESS);
}
