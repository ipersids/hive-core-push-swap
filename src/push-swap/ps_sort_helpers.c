/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:33:18 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 16:38:57 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static void	init_parts_a(t_parts *part, t_partition *this_loc);
static void	init_parts_b(t_parts *part, t_partition *this_loc);

/* --------------------------- Public Functions ---------------------------- */

void	ps_correct_this_loc(t_data *data, t_partition *this_loc)
{
	if (TAIL_A == this_loc->loc && data->a.len == this_loc->size)
		this_loc->loc = HEAD_A;
	if (TAIL_B == this_loc->loc && data->b.len == this_loc->size)
		this_loc->loc = HEAD_B;
}

void	ps_init_parts(t_parts *part, t_partition *this_loc)
{
	part->max.size = 0;
	part->mid.size = 0;
	part->min.size = 0;
	if (HEAD_A == this_loc->loc || TAIL_A == this_loc->loc)
		init_parts_a(part, this_loc);
	if (HEAD_B == this_loc->loc || TAIL_B == this_loc->loc)
		init_parts_b(part, this_loc);
}

/* ------------------- Private Function Implementation --------------------- */

static void	init_parts_a(t_parts *part, t_partition *this_loc)
{
	if (HEAD_A == this_loc->loc)
	{
		part->min.loc = TAIL_B;
		part->mid.loc = HEAD_B;
		part->max.loc = TAIL_A;
		return ;
	}
	if (TAIL_A == this_loc->loc)
	{
		part->min.loc = TAIL_B;
		part->mid.loc = HEAD_B;
		part->max.loc = HEAD_A;
	}
}

static void	init_parts_b(t_parts *part, t_partition *this_loc)
{
	if (HEAD_B == this_loc->loc)
	{
		part->min.loc = TAIL_B;
		part->mid.loc = TAIL_A;
		part->max.loc = HEAD_A;
	}
	if (TAIL_B == this_loc->loc)
	{
		part->min.loc = HEAD_B;
		part->mid.loc = TAIL_A;
		part->max.loc = HEAD_A;
	}
}
