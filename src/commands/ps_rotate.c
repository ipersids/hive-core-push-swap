/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:34:34 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 16:41:14 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_bool	rotate(t_queue *this);

/* --------------------------- Public Functions ---------------------------- */

void	ps_rotate_a(t_data *data)
{
	if (!rotate(&data->a))
		return ;
	ps_save_command(data, ra);
}

void	ps_rotate_b(t_data *data)
{
	if (!rotate(&data->b))
		return ;
	ps_save_command(data, rb);
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
