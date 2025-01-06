/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_dequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:23:40 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 21:23:50 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Removes first value from a queue.
 * 
 * @param stack Pointer to the queue (circular buffer) structure.
 * @return t_bool Returns TRUE if the element is successfully removed, 
 * 				  FALSE if the buffer is empty.
 */
int	queue_dequeue(t_queue *stack)
{
	int		value;

	if (queue_empty(stack))
		return (-1);
	value = stack->buf[stack->read];
	stack->read = (stack->read + 1) % stack->size;
	stack->len = stack->len - 1;
	return (value);
}
