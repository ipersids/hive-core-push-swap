/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_add_vip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:41:48 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:56 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Puts an element to the top of the queue (renew ride index).
 * 
 * Just because FIFO is not enough for some VIP numbers :)
 * 
 * @param stack Pointer to the queue (the circular buffer) structure.
 * @param num The element to be added to the head of queue.
 * @return t_bool Returns TRUE if the element is successfully added, 
 * 				  FALSE if the buffer is full.
 */
t_bool	queue_add_vip(t_queue *stack, int num)
{
	size_t	index;

	if (queue_full(stack))
		return (FALSE);
	index = (stack->read - 1) % stack->size;
	if (0 == stack->read)
		index = stack->size - 1;
	stack->buf[index] = num;
	stack->read = index;
	stack->len = stack->len + 1;
	return (TRUE);
}
