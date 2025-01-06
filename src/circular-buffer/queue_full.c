/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_full.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:17:15 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:45 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Checks if a queue (circular buffer) is full.
 * 
 * @param buf Pointer to the queue structure.
 * @return t_bool Returns TRUE if the buffer is full, FALSE otherwise.
 */
t_bool	queue_full(t_queue *stack)
{
	return (stack->len == stack->size && stack->read == stack->write);
}
