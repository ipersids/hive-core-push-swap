/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:23:39 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 00:40:09 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_to_parts(t_data *data, t_partition *this_loc, t_parts *part);
static void set_partition_limits(t_partition *this_loc, int *pivot_1, \
								int *pivot_2);

void	ps_sort(t_data *data, t_partition *this_loc)
{
	t_parts	part;

	ps_correct_this_loc(data, this_loc);
	if (3 >= this_loc->size)
	{
		// ft_printf("\nBEFORE OUT (this_loc.loc = %d, this_loc.size = %d)\n", (int)this_loc->loc, (int)this_loc->size);
		// tmp_print_stack(&data->a, 'A');
		// tmp_print_stack(&data->b, 'B');
		if (3 == this_loc->size)
			ps_sort_three(data, this_loc);
		if (2 == this_loc->size)
			ps_sort_two(data, this_loc);
		if (1 == this_loc->size)
			ps_sort_one(data, this_loc);
		// ft_printf("AFTER OUT (this_loc.loc = %d, this_loc.size = %d)\n", (int)this_loc->loc, (int)this_loc->size);
		// tmp_print_stack(&data->a, 'A');
		// tmp_print_stack(&data->b, 'B');
		return ;
	}
	ps_init_parts(&part, this_loc);
	divide_to_parts(data, this_loc, &part);
	ps_sort(data, &part.max);
	ps_sort(data, &part.mid);
	ps_sort(data, &part.min);
}

static void	divide_to_parts(t_data *data, t_partition *this_loc, t_parts *part)
{
	int	pivot_1;
	int	pivot_2;
	int	max;
	int	num;

	max = ps_max_value(data, this_loc);
	pivot_1 = 0;
	pivot_2 = 0;
	set_partition_limits(this_loc, &pivot_1, &pivot_2);
	while (this_loc->size)
	{
		num = ps_read_value(data, this_loc);
		if (num > max - pivot_2)
			part->max.size += ps_move_from_to(data, this_loc->loc, part->max.loc);
		else if (num > max - pivot_1)
			part->mid.size += ps_move_from_to(data, this_loc->loc, part->mid.loc);
		else
			part->min.size += ps_move_from_to(data, this_loc->loc, part->min.loc);
		this_loc->size--;
	}
}

static void set_partition_limits(t_partition *this_loc, int *pivot_1, int *pivot_2)
{
	*pivot_2 = this_loc->size / 3;
	if (HEAD_A == this_loc->loc || TAIL_A == this_loc->loc)
		*pivot_1 = 2 * this_loc->size / 3;
	if (HEAD_B == this_loc->loc || TAIL_B == this_loc->loc)
		*pivot_1 = this_loc->size / 2;
}
