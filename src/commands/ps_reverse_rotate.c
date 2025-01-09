/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:41:49 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 20:16:42 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_bool	reverse_rotate(t_queue *this);

/* --------------------------- Public Functions ---------------------------- */

t_bool	ps_rev_rotate_a(t_data *data)
{
	if (!reverse_rotate(&data->a))
		return (FALSE);
	ps_save_command(data, rra);
	return (TRUE);
}

t_bool	ps_rev_rotate_b(t_data *data)
{
	if (!reverse_rotate(&data->b))
		return (FALSE);
	ps_save_command(data, rrb);
	return (TRUE);
}

void	ps_rev_rotate_ab(t_data *data)
{
	ps_rev_rotate_a(data);
	ps_rev_rotate_b(data);
}

/* ------------------- Private Function Implementation --------------------- */

static t_bool	reverse_rotate(t_queue *this)
{
	int	num;

	if (!this || queue_empty(this) || 2 > this->len)
		return (FALSE);
	num = queue_remove_last(this);
	queue_add_vip(this, num);
	return (TRUE);
}
