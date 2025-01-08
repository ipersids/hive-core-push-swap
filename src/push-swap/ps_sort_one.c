/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:47:24 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 17:48:29 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_one(t_data *data, t_partition *from)
{
	if (TAIL_A == from->loc || HEAD_B == from->loc || TAIL_B == from->loc)
		ps_move_from_to(data, from->loc, HEAD_A);
	from->size = from->size - 1;
}
