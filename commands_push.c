/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 01:54:09 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/16 02:19:33 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static t_push_swap	*push(t_push_swap **dest, t_push_swap **src);

/* --------------------------- Public Functions ---------------------------- */

/**
 * @brief Take the first element at the top of b and put it at the top of a.
 * 		  Do nothing if b is empty.
 * @param a Pointer to the stack a (destination).
 * @param b Pointer to the stack b  (source).
 */
void	ps_push_a(t_push_swap **a, t_push_swap **b)
{
	if (!push(a, b))
		return ;
	write(1, "pa\n", 3);
}

/**
 * @brief Take the first element at the top of a and put it at the top of b.
 * 		  Do nothing if a is empty.
 * @param b Pointer to the stack b (destination).
 * @param a Pointer to the stack a (source).
 */
void	ps_push_b(t_push_swap **b, t_push_swap **a)
{
	if (!push(b, a))
		return ;
	write(1, "pb\n", 3);
}

/* ------------------- Private Function Implementation --------------------- */

/**
 * @brief Take the first element at the top of src 
 * 		  and put it at the top of dest.
 * 		  Do nothing if src is empty.
 * 
 * @param dest Pointer to the destination.
 * @param src Pointer to the stack source.
 * @return t_push_swap* Pointer to the head of destination or NULL is an error.
 */
static t_push_swap	*push(t_push_swap **dest, t_push_swap **src)
{
	t_push_swap	*tmp;

	if (!dest || !src || !(*src))
		return (NULL);
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (!(*dest))
	{
		*dest = tmp;
		(*dest)->next = NULL;
		return (*dest);
	}
	(*dest)->prev = tmp;
	tmp->next = *dest;
	*dest = tmp;
	return (*dest);
}
