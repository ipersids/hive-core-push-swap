/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:49:23 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/05 23:31:20 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	*numbers;
	int	numbers_size;
	t_circ_buf	stack;

	numbers_size = 0;
	numbers = NULL;
	numbers = ps_get_numbers(argc, argv, numbers, &numbers_size);
	if (!numbers)
		ps_exit_error(EXIT_FAILURE);
	
	// >>> TESTING
	for (int i = 0; i < numbers_size; i++) {
		ft_printf("%d", numbers[i]);
		if (i != numbers_size - 1)
			ft_printf(", ");
	}
	ft_printf("\n\n");
	ft_printf("%d\n", numbers_size);
	if (!circular_buf_init(&stack, numbers_size))
	{
		ft_printf("1\n");
		free(numbers);
		free(stack.buf);
		ps_exit_error(EXIT_FAILURE);
	}
	ft_printf("BUF SIZE: %d\n", (int)stack.maxlen);
	if (!circular_buf_fill(&stack, numbers, numbers_size))
	{
		ft_printf("2\n");
		free(numbers);
		ps_exit_error(EXIT_FAILURE);
	}
	ft_printf("\n");
	for (size_t i = stack.read; i < stack.write; i++) {
		ft_printf("%d, ", stack.buf[i]);
	}
	ft_printf("\n");

	free(numbers);
	free(stack.buf);
	// <<< END
	
	return (0);
}
