/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_enqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:03:11 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:01 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Puts an element to the write index of the queue.
 * 
 * This function adds an element to the circular buffer. If the buffer is full,
 * it will not add the element and will return FALSE.
 * 
 * @param stack Pointer to the queue (the circular buffer) structure.
 * @param num The element to be added to the end of queue.
 * @return t_bool Returns TRUE if the element is successfully added, 
 * 				  FALSE if the buffer is full.
 */
t_bool	queue_enqueue(t_queue *stack, int num)
{
	if (queue_full(stack))
		return (FALSE);
	stack->buf[stack->write] = num;
	stack->write = (stack->write + 1) % stack->size;
	stack->len = stack->len + 1;
	return (TRUE);
}
