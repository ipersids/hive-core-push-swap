/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:39:55 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 17:46:55 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_two(t_data *data, t_partition *from)
{
	t_queue	*stack;

	if (TAIL_A == from->loc || HEAD_B == from->loc || TAIL_B == from->loc)
	{
		ps_move_from_to(data, from->loc, HEAD_A);
		ps_move_from_to(data, from->loc, HEAD_A);
	}
	stack = &data->a;
	if (stack->buf[stack->read] > stack->buf[(stack->read + 1) % stack->size])
		ps_swap_a(data);
	from->size = from->size - 2;
}
