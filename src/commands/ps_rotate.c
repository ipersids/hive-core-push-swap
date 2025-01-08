/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:34 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 13:39:19 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_bool	rotate(t_queue *this);

/* --------------------------- Public Functions ---------------------------- */

t_bool	ps_rotate_a(t_data *data)
{
	if (!rotate(&data->a))
		return (FALSE);
	ps_save_command(data, ra);
	return (TRUE);
}

t_bool	ps_rotate_b(t_data *data)
{
	if (!rotate(&data->b))
		return (FALSE);
	ps_save_command(data, rb);
	return (TRUE);
}

/* ------------------- Private Function Implementation --------------------- */

static t_bool	rotate(t_queue *this)
{
	int	num;

	if (!this || queue_empty(this) || 2 > this->len)
		return (FALSE);
	num = queue_dequeue(this);
	queue_enqueue(this, num);
	return (TRUE);
}
