/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:40 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 22:08:43 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	*line;

	ps_data_init(&data, TRUE);
	ps_get_numbers(argc, argv, &data.input.num, &data.input.len);
	if (!data.input.num)
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	if (!ps_stacks_init(&data))
		ps_destroy_data_exit(&data, EXIT_FAILURE);
	line = get_next_line(0, FALSE);
	checker_is_presorted(&data, line);
	checker_do_command(&data, line);
	if (0 != data.b.len)
	{
		ft_printf("KO\n");
		ps_destroy_data_exit(&data, EXIT_SUCCESS);
	}
	checker_is_aftersorted(&data);
	ft_printf("OK\n");
	ps_destroy_data_exit(&data, EXIT_SUCCESS);
}
