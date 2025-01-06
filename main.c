/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:49:23 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 21:59:06 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void tmp_print_stack(t_queue *stack) {
	size_t indx;
	ft_printf("Queue size = %d, ", (int)stack->size);
	ft_printf("current len = %d\n",(int)stack->len);
	for (size_t i = 0; i < stack->len; i++) {
		indx = (stack->read + i) % stack->size;
		ft_printf("%d [%d], ", (int)stack->buf[indx], (int)i);
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int	*numbers;
	int	numbers_size;
	t_queue stack;

	numbers_size = 0;
	numbers = NULL;
	numbers = ps_get_numbers(argc, argv, numbers, &numbers_size);
	if (!numbers)
		ps_exit_error(EXIT_FAILURE);
	
	// >>> TESTING
	if (!queue_init(&stack, numbers_size + 10))
	{
		free(numbers);
		return (-1);
	}
	for (int i = 0; i < numbers_size; i++) {
		ft_printf("%d", numbers[i]);
		if (i != numbers_size - 1)
			ft_printf(", ");
		queue_enqueue(&stack, numbers[i]);
	}
	ft_printf("\n\n");
	tmp_print_stack(&stack);

	ft_printf("\nEnqueue element = 15:\n");
	queue_enqueue(&stack, 15);
	tmp_print_stack(&stack);

	ft_printf("\nAdd element = -15 to the top of queue:\n");
	queue_add_vip(&stack, -15);
	tmp_print_stack(&stack);

	ft_printf("\nDequeue:\n");
	int res = queue_dequeue(&stack);
	ft_printf("Removed element = %d\n", res);
	tmp_print_stack(&stack);

	ft_printf("\nTry to enqueue 15 more elements to the queue:\n");
	for (int i = 0; i < 15; i++) {
		if (!queue_enqueue(&stack, 99)) {
			ft_printf("Added %d elements, now the queue is full\n", i);
			break;
		}
	}
	tmp_print_stack(&stack);

	ft_printf("\nDequeue until it is empty:\nRemoved: ");
	while (!queue_empty(&stack)) {
		ft_printf("%d, ", queue_dequeue(&stack));
	}
	ft_printf("\n");
	tmp_print_stack(&stack);

	free(numbers);
	queue_free(&stack);
	// <<< END
	
	return (0);
}
