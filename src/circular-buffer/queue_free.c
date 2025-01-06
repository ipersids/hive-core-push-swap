/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:00:12 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 21:03:33 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Frees buffer memory of the queue structure.
 * 
 * @param stack Pointer to the queue (the circular buffer) structure.
 */
void	queue_free(t_queue *stack)
{
	if (!stack)
		return ;
	if (stack->buf)
		free(stack->buf);
}
