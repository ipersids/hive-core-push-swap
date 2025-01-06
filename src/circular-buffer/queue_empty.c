/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_empty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:19:32 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:51 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Checks if a queue (circular buffer) is empty.
 * 
 * @param buf Pointer to the queue structure.
 * @return t_bool Returns TRUE if the buffer is empty, FALSE otherwise.
 */
t_bool	queue_empty(t_queue *stack)
{
	return (0 == stack->len && stack->read == stack->write);
}
