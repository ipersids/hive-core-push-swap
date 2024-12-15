/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 17:17:17 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/15 18:19:10 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*ps_lst_new(int num)
{
	t_push_swap	*node;

	node = (t_push_swap *) malloc(sizeof(t_push_swap));
	if (!node)
	{
		write(1, "Error: Memory allocation fails.\n", 32);
		return (NULL);
	}
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

t_push_swap	*ps_lst_add_front(t_push_swap **lst, t_push_swap *new_node)
{
	if (!lst || !new_node)
		return (NULL);
	if (!(*lst))
	{
		*lst = new_node;
		return (*lst);
	}
	new_node->next = *lst;
	(*lst)->prev = new_node;
	*lst = new_node;
	return (*lst);
}

void	ps_lst_free(t_push_swap **lst)
{
	t_push_swap	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		printf("Freeing node p=%p, num=%d\n", tmp, tmp->num);
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = (*lst);
	}
	*lst = NULL;
}
