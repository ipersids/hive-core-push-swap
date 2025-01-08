/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_move_from_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:21:24 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 14:39:42 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	move_from_head_a(t_data *data, t_loc dst_loc);
static size_t	move_from_tail_a(t_data *data, t_loc dst_loc);
static size_t	move_from_head_b(t_data *data, t_loc dst_loc);
static size_t	move_from_tail_b(t_data *data, t_loc dst_loc);

size_t	ps_move_from_to(t_data *data, t_loc this_loc, t_loc dst_loc)
{
	size_t	size;

	size = 0;
	if (HEAD_A == this_loc)
		size += move_from_head_a(data, dst_loc);
	else if (TAIL_A == this_loc)
		size += move_from_tail_a(data, dst_loc);
	else if (HEAD_B == this_loc)
		size += move_from_head_b(data, dst_loc);
	else
		size += move_from_tail_b(data, dst_loc);
	return (size);
}

static size_t	move_from_head_a(t_data *data, t_loc dst_loc)
{
	if (HEAD_B == dst_loc)
		return (ps_push_b(data));
	if (TAIL_A == dst_loc)
		return (ps_rotate_a(data));
	if (TAIL_B == dst_loc)
	{
		if (ps_push_b(data))
		{
			ps_rotate_b(data);
			return (1);
		}
	}
	return (0);
}

static size_t	move_from_tail_a(t_data *data, t_loc dst_loc)
{
	if (HEAD_A == dst_loc)
		return(ps_rev_rotate_a(data));
	if (HEAD_B == dst_loc)
	{
		ps_rev_rotate_a(data);
		ps_push_b(data);
		return (1);
	}
	if (TAIL_B == dst_loc)
	{
		ps_rev_rotate_a(data);
		ps_push_b(data);
		ps_rotate_b(data);
		return (1);
	}
	return (0);
}

static size_t	move_from_head_b(t_data *data, t_loc dst_loc)
{
	if (HEAD_A == dst_loc)
		return (ps_push_a(data));
	if (TAIL_B == dst_loc)
		return (ps_rotate_b(data));
	if (TAIL_A == dst_loc)
	{
		if (ps_push_a(data))
		{
			ps_rotate_a(data);
			return (1);
		}
	}
	return (0);
}

static size_t	move_from_tail_b(t_data *data, t_loc dst_loc)
{
	if (HEAD_B == dst_loc)
		return(ps_rev_rotate_b(data));
	if (HEAD_A == dst_loc)
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
		return (1);
	}
	if (TAIL_A == dst_loc)
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
		ps_rotate_a(data);
		return (1);
	}
	return (0);
}
