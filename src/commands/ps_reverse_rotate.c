/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:41:49 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 17:06:42 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_bool	reverse_rotate(t_queue *this);

/* --------------------------- Public Functions ---------------------------- */

void	ps_rev_rotate_a(t_data *data)
{
	if (!reverse_rotate(&data->a))
		return ;
	ps_save_command(data, rra);
}

void	ps_rev_rotate_b(t_data *data)
{
	if (!reverse_rotate(&data->b))
		return ;
	ps_save_command(data, rrb);
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
