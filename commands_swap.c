/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 19:21:14 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/16 02:13:10 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_push_swap	*swap(t_push_swap **lst);

/* --------------------------- Public Functions ---------------------------- */

void	ps_swap(t_push_swap **a, t_push_swap **b)
{
	t_push_swap	*sa;
	t_push_swap	*sb;

	sa = swap(a);
	sb = swap(b);
	if (!sa && !sb)
		return ;
	if (!sa)
		write(1, "sb\n", 3);
	else if (!sb)
		write(1, "sa\n", 3);
	else
		write(1, "ss\n", 3);
}

/* ------------------- Private Function Implementation --------------------- */

/**
 * @brief Swap the first 2 elements at the top of stack.
 * 		  Do nothing if there is only one or no elements.
 * @param lst Pointer to the top of stack.
 */
static t_push_swap	*swap(t_push_swap **lst)
{
	t_push_swap	*first;
	t_push_swap	*second;

	if (!lst || !*lst || NULL == (*lst)->next)
		return (NULL);
	first = *lst;
	second = (*lst)->next;
	second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	*lst = second;
	return (*lst);
}
