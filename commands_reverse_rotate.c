/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:57:11 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/16 22:09:09 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_push_swap	*reverse_rotate(t_push_swap **lst);

/* --------------------------- Public Functions ---------------------------- */

/**
 * @brief Shift down all elements of stacks a and/or b and print the command.
 * 		  The last element becomes the first one.
 * @param a stack a or NULL
 * @param b stack b or NULL
 */
void	ps_reverse_rotate(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*rra;
	t_push_swap	*rrb;

	rra = reverse_rotate(a);
	rrb = reverse_rotate(b);
	if (!rra && !rrb)
		return ;
	if (!rra)
		write(1, "rrb\n", 4);
	else if (!rrb)
		write(1, "rra\n", 4);
	else
		write(1, "rrr\n", 4);
}

/* ------------------- Private Function Implementation --------------------- */

/**
 * @brief Shift down all elements of stack a by 1.
 * 		  The last element becomes the first one.
 * 		  Do nothing if there only one node in stack.
 * @param lst Pointer to the first node of stack.
 * @return Pointer to the new head of stack.
*/
static t_push_swap	*reverse_rotate(t_push_swap **lst)
{
	t_push_swap	*last;

	if (!lst || !(*lst) || NULL == (*lst)->next)
		return (NULL);
	last = ps_lst_find_last(lst);
	last->prev->next = NULL;
	(*lst)->prev = last;
	last->prev = NULL;
	last->next = *lst;
	*lst = last;
	return (*lst);
}
