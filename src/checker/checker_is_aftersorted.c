/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_is_aftersorted.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:23:25 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/10 01:39:24 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_is_aftersorted(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = data->a.read;
	len = data->a.len;
	while (len)
	{
		j = (i + 1) % data->a.size;
		while (data->a.write != j)
		{
			if (data->a.buf[i] > data->a.buf[j])
			{
				ft_printf("KO\n");
				ps_destroy_data_exit(data, EXIT_SUCCESS);
			}
			j = (j + 1) % data->a.size;
		}
		i = (i + 1) % data->a.size;
		len--;
	}
}
