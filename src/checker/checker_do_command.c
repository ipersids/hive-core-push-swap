/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_do_command.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:19:24 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 21:40:52 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void			do_command(t_data *data, t_command command);
static t_command	is_command_valid(char *line);

void	checker_do_command(t_data *data, char *line)
{
	t_command	command;

	while (NULL != line)
	{
		command = is_command_valid(line);
		if (0 == command || MAX_COMMANDS <= command)
		{
			free(line);
			ps_destroy_data_exit(data, EXIT_FAILURE);
		}
		free(line);
		do_command(data, command);
		line = get_next_line(0, FALSE);
	}
	get_next_line(0, TRUE);
}

static void	do_command(t_data *data, t_command command)
{
	if (sa == command)
		ps_swap_a(data);
	else if (sb == command)
		ps_swap_b(data);
	else if (ss == command)
		ps_swap_ab(data);
	else if (pa == command)
		ps_push_a(data);
	else if (pb == command)
		ps_push_b(data);
	else if (ra == command)
		ps_rotate_a(data);
	else if (rb == command)
		ps_rotate_b(data);
	else if (rr == command)
		ps_rotate_ab(data);
	else if (rra == command)
		ps_rev_rotate_a(data);
	else if (rrb == command)
		ps_rev_rotate_b(data);
	else if (rrr == command)
		ps_rev_rotate_ab(data);
}

static t_command	is_command_valid(char *line)
{
	if (0 == ft_strncmp(line, "sa\n", sizeof(line)))
		return (sa);
	if (0 == ft_strncmp(line, "sb\n", sizeof(line)))
		return (sb);
	if (0 == ft_strncmp(line, "ss\n", sizeof(line)))
		return (ss);
	if (0 == ft_strncmp(line, "pa\n", sizeof(line)))
		return (pa);
	if (0 == ft_strncmp(line, "pb\n", sizeof(line)))
		return (pb);
	if (0 == ft_strncmp(line, "ra\n", sizeof(line)))
		return (ra);
	if (0 == ft_strncmp(line, "rb\n", sizeof(line)))
		return (rb);
	if (0 == ft_strncmp(line, "rr\n", sizeof(line)))
		return (rr);
	if (0 == ft_strncmp(line, "rra\n", sizeof(line)))
		return (rra);
	if (0 == ft_strncmp(line, "rrb\n", sizeof(line)))
		return (rrb);
	if (0 == ft_strncmp(line, "rrr\n", sizeof(line)))
		return (rrr);
	return (0);
}
