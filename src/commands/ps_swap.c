/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:56:01 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 13:40:03 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_bool	swap(t_queue *where);

/* --------------------------- Public Functions ---------------------------- */

t_bool	ps_swap_a(t_data *data)
{
	if (!swap(&data->a))
		return (FALSE);
	ps_save_command(data, sa);
	return (TRUE);
}

t_bool	ps_swap_b(t_data *data)
{
	if (!swap(&data->b))
		return (FALSE);
	ps_save_command(data, sb);
	return (TRUE);
}

/* ------------------- Private Function Implementation --------------------- */

static t_bool	swap(t_queue *where)
{
	int	num1;
	int	num2;

	if (!where || !where->buf || 2 > where->len)
		return (FALSE);
	num1 = queue_dequeue(where);
	num2 = queue_dequeue(where);
	queue_add_vip(where, num1);
	queue_add_vip(where, num2);
	return (TRUE);
}
