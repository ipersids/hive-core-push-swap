/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:20:29 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 13:38:03 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_bool	push(t_queue *src, t_queue *dest);

/* --------------------------- Public Functions ---------------------------- */

t_bool	ps_push_a(t_data *data)
{
	if (!push(&data->b, &data->a))
		return (FALSE);
	ps_save_command(data, pa);
	return (TRUE);
}

t_bool	ps_push_b(t_data *data)
{
	if (!push(&data->a, &data->b))
		return (FALSE);
	ps_save_command(data, pb);
	return (TRUE);
}

/* ------------------- Private Function Implementation --------------------- */

static t_bool	push(t_queue *src, t_queue *dest)
{
	int	num;

	if (!src || queue_empty(src) || !dest || queue_full(dest))
		return (FALSE);
	num = queue_dequeue(src);
	queue_add_vip(dest, num);
	return (TRUE);
}
