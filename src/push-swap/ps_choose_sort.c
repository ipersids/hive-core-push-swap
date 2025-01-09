/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_choose_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:16:41 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 16:40:24 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static void	hardcode_sort_three(t_data *data);
static void	hardcode_sort_five(t_data *data);

/* --------------------------- Public Functions ---------------------------- */

void	ps_choose_sort(t_data *data, t_partition *this_loc)
{
	if (3 == data->a.size)
		hardcode_sort_three(data);
	else if (5 == data->a.size)
		hardcode_sort_five(data);
	else
		ps_sort(data, this_loc);
}

/* ------------------- Private Function Implementation --------------------- */

static void	hardcode_sort_three(t_data *data)
{
	int	one;
	int	two;
	int	three;

	one = data->a.buf[data->a.read];
	two = data->a.buf[(data->a.read + 1) % data->a.size];
	three = data->a.buf[(data->a.read + 2) % data->a.size];
	if (one > two && three > two && three > one)
		ps_swap_a(data);
	else if (one > two && three > two && one > three)
		ps_rotate_a(data);
	else if (two > one && two > three && one > three)
		ps_rev_rotate_a(data);
	else if (two > one && two > three && three > one)
	{
		ps_swap_a(data);
		ps_rotate_a(data);
	}
	else if (one > two && two > three && one > three)
	{
		ps_swap_a(data);
		ps_rev_rotate_a(data);
	}
}

static void	hardcode_sort_five(t_data *data)
{
	while (3 < data->a.len)
	{
		if (3 > data->a.buf[data->a.read])
			ps_push_b(data);
		else
			ps_rotate_a(data);
	}
	if (data->b.buf[data->b.read] \
		< data->b.buf[(data->b.read + 1) % data->b.size])
		ps_swap_b(data);
	hardcode_sort_three(data);
	ps_push_a(data);
	ps_push_a(data);
}
