/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_save_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 17:09:35 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 17:42:23 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_save_command(t_data *data, t_command command)
{
	t_storage	*this;
	int8_t		*tmp;

	this = &data->command;
	if (this->capacity >= this->len)
	{
		tmp = ft_realloc(this->list, this->capacity, this->capacity * 2);
		if (!tmp)
			ps_destroy_data_exit(data, EXIT_FAILURE);
		this->capacity = this->capacity * 2;
		this->list = tmp;
	}
	this->list[this->len] = command;
	this->len++;
}
