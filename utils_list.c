/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:17:17 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/17 16:14:17 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*ps_lst_new(int num)
{
	t_push_swap	*node;

	node = (t_push_swap *) malloc(sizeof(t_push_swap));
	if (!node)
		return (NULL);
	node->num = num;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

size_t	ps_lst_len(t_push_swap *start)
{
	size_t		len;
	t_push_swap	*curr_node;

	len = 0;
	curr_node = start;
	while (curr_node)
	{
		curr_node = curr_node->next;
		len++;
	}
	return (len);
}

t_push_swap	*ps_lst_add_back(t_push_swap **lst, t_push_swap *new_node)
{
	t_push_swap	*last;

	if (!lst || !new_node)
		return (NULL);
	if (!(*lst))
	{
		*lst = new_node;
		return (*lst);
	}
	last = ps_lst_find_last(lst);
	last->next = new_node;
	new_node->prev = last;
	return (last->next);
}

void	ps_lst_free(t_push_swap **lst)
{
	t_push_swap	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = (*lst);
	}
	*lst = NULL;
}

t_push_swap	*ps_lst_find_last(t_push_swap **lst)
{
	t_push_swap	*curr;

	if (!lst || !(*lst))
		return (NULL);
	curr = (*lst);
	while (curr->next)
		curr = curr->next;
	return (curr);
}
