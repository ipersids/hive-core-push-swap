/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_data_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:54:59 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 16:55:26 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_data_init(t_data *data, t_bool is_checker)
{
	data->a.buf = NULL;
	data->a.len = 0;
	data->a.read = 0;
	data->a.write = 0;
	data->a.size = 0;
	data->b.buf = NULL;
	data->b.len = 0;
	data->b.read = 0;
	data->b.write = 0;
	data->b.size = 0;
	data->command.list = NULL;
	data->command.len = 0;
	data->command.capacity = 0;
	data->input.num = NULL;
	data->input.len = 0;
	data->is_checker = is_checker;
}
