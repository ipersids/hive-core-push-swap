/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 22:48:01 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:19 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static char	*get_commang_string(t_command i);

/* --------------------------- Public Functions ---------------------------- */

void	ps_print_commands(t_storage *command)
{
	size_t	i;

	i = 0;
	while (i < command->len)
	{
		ft_printf("%s", get_commang_string(command->list[i]));
		i++;
	}
}

/* ------------------- Private Function Implementation --------------------- */

static char	*get_commang_string(t_command i)
{
	static char	list[MAX_COMMANDS][10] = {
		"",
		"sa\n",
		"sb\n",
		"ss\n",
		"pa\n",
		"pb\n",
		"ra\n",
		"rb\n",
		"rr\n",
		"rra\n",
		"rrb\n",
		"rrr\n"
	};

	return (list[i]);
}
