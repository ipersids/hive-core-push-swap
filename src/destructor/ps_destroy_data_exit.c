/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_destroy_data_exit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:44:24 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 14:14:05 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_destroy_data_exit(t_data *data, int exit_code)
{
	if (EXIT_FAILURE == exit_code)
		ft_printf("Error\n");
	if (data->a.buf)
		queue_free(&data->a);
	if (data->b.buf)
		queue_free(&data->b);
	if (data->command.list)
		free(data->command.list);
	if (data->input.num)
		free(data->input.num);
	exit(exit_code);
}
