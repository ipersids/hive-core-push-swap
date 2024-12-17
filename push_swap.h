/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:09:46 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/17 14:27:37 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// @note delete debugging headers
#include <stdio.h>
/// <<< end of notes

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

typedef struct s_push_swap
{
	int					num;
	struct s_push_swap	*prev;
	struct s_push_swap	*next;
}						t_push_swap;

/* -------------------------- Linked List Functions ------------------------ */

t_push_swap	*ps_lst_new(int num);
size_t		ps_lst_len(t_push_swap *start);
t_push_swap	*ps_lst_add_back(t_push_swap **lst, t_push_swap *new_node);
void		ps_lst_free(t_push_swap **lst);
t_push_swap	*ps_lst_find_last(t_push_swap **lst);

/* -------------------------------- Commands ------------------------------- */

void		ps_swap(t_push_swap **a, t_push_swap **b);
void		ps_push_a(t_push_swap **a, t_push_swap **b);
void		ps_push_b(t_push_swap **b, t_push_swap **a);
void		ps_rotate(t_push_swap **a, t_push_swap **b);
void		ps_reverse_rotate(t_push_swap **a, t_push_swap **b);

#endif