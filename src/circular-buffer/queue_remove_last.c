/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_remove_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:49 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 16:57:30 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

int		queue_remove_last(t_queue *stack)
{
	int		num;
	size_t	indx;

	if (queue_empty(stack))
		return (-1);
	if (0 == stack->write)
		indx = stack->size - 1;
	else
		indx = (stack->write - 1) % stack->size;
	num = stack->buf[indx];
	stack->write = indx;
	stack->len = stack->len - 1;
	return (num);
}
