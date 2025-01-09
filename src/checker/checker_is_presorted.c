/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_is_presorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:07:10 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 21:58:21 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_is_presorted(t_data *data, char *line)
{
	t_bool	is_sorted;

	is_sorted = ps_sorted_ascending(data->input.num, data->input.len);
	if (is_sorted && !line)
	{
		ft_printf("OK\n");
		ps_destroy_data_exit(data, EXIT_SUCCESS);
	}
	else if (!is_sorted && !line)
	{
		ft_printf("KO\n");
		ps_destroy_data_exit(data, EXIT_SUCCESS);
	}
}
