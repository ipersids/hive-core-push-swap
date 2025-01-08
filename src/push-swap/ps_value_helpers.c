/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_value_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:01:18 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 00:26:47 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_read_value(t_data *data, t_partition *this_loc)
{
	t_queue	*stack;
	size_t	i;

	stack = ps_which_stack(data, this_loc);
	i = stack->read;
	if (TAIL_A == this_loc->loc || TAIL_B == this_loc->loc)
	{
		i = stack->write - 1;
		if (stack->write == 0)
			i = stack->size - 1;
	}
	return (stack->buf[i]);
}

int	ps_max_value(t_data *data, t_partition *loc)
{
	t_queue	*stack;
	int		max;
	size_t	i;
	size_t	j;

	max = 0;
	stack = ps_which_stack(data, loc);
	if (HEAD_A == loc->loc || HEAD_B == loc->loc)
		i = stack->read;
	else
		i = (stack->read + (stack->len - loc->size)) % stack->size;
	j = 0;
	while (j++ < loc->size)
	{
		if (stack->buf[i] > max)
			max = stack->buf[i];
		i = (i + 1) % stack->size;
	}
	return (max);
}

t_queue	*ps_which_stack(t_data *data, t_partition *this_loc)
{
	if (HEAD_A == this_loc->loc || TAIL_A == this_loc->loc)
		return (&data->a);
	return (&data->b);
}
