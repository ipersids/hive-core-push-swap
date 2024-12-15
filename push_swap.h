/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:09:46 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/15 18:14:09 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_push_swap
{
	int					num;
	struct s_push_swap	*prev;
	struct s_push_swap	*next;
}						t_push_swap;

/* -------------------------- Linked List Functions ------------------------ */

t_push_swap	*ps_lst_new(int num);
size_t		ps_lst_len(t_push_swap *start);
t_push_swap	*ps_lst_add_front(t_push_swap **lst, t_push_swap *new_node);
void		ps_lst_free(t_push_swap **lst);

#endif