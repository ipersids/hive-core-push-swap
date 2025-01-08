/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_save_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:35 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/08 19:31:06 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_save_command(t_data *data, t_command command)
{
	size_t	old_capacity;
	int8_t	*tmp;

	if (data->command.len >= data->command.capacity)
	{
		old_capacity = data->command.capacity;
		tmp = ft_realloc(data->command.list, old_capacity, old_capacity * 2);
		if (!tmp)
			ps_destroy_data_exit(data, EXIT_FAILURE);
		data->command.capacity = data->command.capacity * 2;
		data->command.list = tmp;
	}
	data->command.list[data->command.len] = command;
	data->command.len = data->command.len + 1;
}
