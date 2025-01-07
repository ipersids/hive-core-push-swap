/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:45:19 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 15:45:10 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ps_stacks_init(t_data *data)
{
	if (!data || !data->input.num || 0 == data->input.len)
		return (FALSE);
	queue_init(&data->a, data->input.len);
	queue_init(&data->b, data->input.len);
	if (!data->a.buf || !data->b.buf)
		return (FALSE);
	ps_rank_ascending(&data->a, data->input.num, data->input.len);
	return (TRUE);
}
