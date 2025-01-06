/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 19:44:08 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 20:56:15 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Initializes a queue as a circular buffer.
 * 
 * @param stack Pointer to the circular buffer structure.
 * @param maxlen Maximum length of the circular buffer.
 * @return t_bool Returns TRUE (1) if the buffer is successfully initialized, 
 * 				  FALSE (0) otherwise.
 */
t_bool	queue_init(t_queue *stack, size_t maxlen)
{
	if (!stack || 0 == maxlen)
		return (FALSE);
	stack->buf = (int *) malloc(maxlen * sizeof(int));
	if (!stack->buf)
		return (FALSE);
	stack->size = maxlen;
	stack->len = 0;
	stack->read = 0;
	stack->write = 0;
	return (TRUE);
}
