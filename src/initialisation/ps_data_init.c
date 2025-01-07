/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:54:59 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 13:50:02 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_data_init(t_data *data)
{
	data->a.buf = NULL;
	data->b.buf = NULL;
	data->command.list = NULL;
	data->command.len = 0;
	data->command.capacity = 0;
	data->input.num = NULL;
	data->input.len = 0;
}
