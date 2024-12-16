/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:03:24 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/16 19:19:08 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_push_swap	*rotate(t_push_swap **lst);

/* --------------------------- Public Functions ---------------------------- */

/**
 * @brief Shift up all elements of stacks a and/or b and print the command.
 * 		  The first element becomes the last one.
 * @param a stack a or NULL
 * @param b stack b or NULL
 */
void	ps_rotate(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*ra;
	t_push_swap	*rb;

	ra = rotate(a);
	rb = rotate(b);
	if (!ra && !rb)
		return ;
	if (!ra)
		write(1, "rb\n", 3);
	else if (!rb)
		write(1, "ra\n", 3);
	else
		write(1, "rr\n", 3);
}

/* ------------------- Private Function Implementation --------------------- */

/** 
 *  @brief Shift up all elements of stack lst by 1.
 * 		   The first element becomes the last one.
 * 		   Do nothing if there only one node in stack.
 *  @param lst Pointer to the first node of stack.
 *  @return Pointer to the new head of stack.
 */
static t_push_swap	*rotate(t_push_swap **lst)
{
	t_push_swap	*last;
	t_push_swap	*node;

	if (!lst || !*lst || !(*lst)->next)
		return (NULL);
	node = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = NULL;
	last = ps_lst_find_last(lst);
	last->next = node;
	node->prev = last;
	node->next = NULL;
	return (*lst);
}
