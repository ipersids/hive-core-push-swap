/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:40:47 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 00:29:17 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static void sort_three_head_a(t_data *data, t_partition *this_loc, int *max);
static void sort_three_tail_a(t_data *data, t_partition *this_loc, int *max);
static void sort_three_head_b(t_data *data, t_partition *this_loc, int *max);
static void sort_three_tail_b(t_data *data, t_partition *this_loc, int *max);

/* --------------------------- Public Functions ---------------------------- */

void	ps_sort_three(t_data *data, t_partition *this_loc)
{
	int		max;

	max = ps_max_value(data, this_loc);
	this_loc->size = this_loc->size - 1;
	if (HEAD_A == this_loc->loc)
		sort_three_head_a(data, this_loc, &max);
	else if (TAIL_A == this_loc->loc)
		sort_three_tail_a(data, this_loc, &max);
	else if (HEAD_B == this_loc->loc)
		sort_three_head_b(data, this_loc, &max);
	else
		sort_three_tail_b(data, this_loc, &max);
}

/* ------------------- Private Function Implementation --------------------- */

static void sort_three_head_a(t_data *data, t_partition *this_loc, int *max)
{
	t_queue	*stack;

	stack = ps_which_stack(data, this_loc);
	if (*max == stack->buf[stack->read])
	{
		ps_swap_a(data);
		ps_rotate_a(data);
		ps_swap_a(data);
		ps_rev_rotate_a(data);
	}
	else if (*max == stack->buf[(stack->read + 1) % stack->size])
	{
		ps_rotate_a(data);
		ps_swap_a(data);
		ps_rev_rotate_a(data);
	}
	ps_sort_two(data, this_loc);
}

static void sort_three_tail_a(t_data *data, t_partition *this_loc, int *max)
{
	t_queue	*stack;

	stack = ps_which_stack(data, this_loc);
	ps_rev_rotate_a(data);
	ps_rev_rotate_a(data);
	if (*max == stack->buf[stack->read])
	{
		ps_swap_a(data);
		ps_rev_rotate_a(data);
	}
	else if (*max == stack->buf[(stack->read + 1) % stack->size])
		ps_rev_rotate_a(data);
	else
	{
		ps_push_b(data);
		ps_rev_rotate_a(data);
		ps_swap_a(data);
		ps_push_a(data);
	}
	this_loc->loc = HEAD_A;
	ps_sort_two(data, this_loc);
}

static void sort_three_head_b(t_data *data, t_partition *this_loc, int *max)
{
	t_queue	*stack;

	stack = ps_which_stack(data, this_loc);
	ps_push_a(data);
	if (*max == stack->buf[stack->read])
	{
		ps_push_a(data);
		ps_swap_a(data);
	}
	else if (*max == stack->buf[(stack->read + 1) % stack->size])
	{
		ps_swap_b(data);
		ps_push_a(data);
		ps_swap_a(data);
	}
	else
		ps_push_a(data);
	ps_push_a(data);
	this_loc->loc = HEAD_A;
	ps_sort_two(data, this_loc);
}

static void sort_three_tail_b(t_data *data, t_partition *this_loc, int *max)
{
	t_queue	*stack;

	stack = ps_which_stack(data, this_loc);
	ps_rev_rotate_b(data);
	ps_rev_rotate_b(data);
	if (*max == stack->buf[stack->read])
	{
		ps_push_a(data);
		ps_rev_rotate_b(data);
	}
	else if (*max == stack->buf[(stack->read + 1) % stack->size])
	{
		ps_swap_b(data);
		ps_push_a(data);
		ps_rev_rotate_b(data);
	}
	else
	{
		ps_rev_rotate_b(data);
		ps_push_a(data);
	}
	this_loc->loc = HEAD_B;
	ps_sort_two(data, this_loc);
}
