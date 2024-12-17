/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:21:04 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/17 15:43:56 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_list(t_push_swap **a, char ch)
{
	t_push_swap *tmp = NULL;
	printf("\nSTACK %c:\n", ch);
		for (tmp = *a; tmp != NULL; tmp = tmp->next) {
			printf("Node [%d]: (%p)\n", tmp->num, tmp);
			printf("\t- next: %p\n", tmp->next);
			printf("\t- prev: %p (%d)\n", tmp->prev, tmp->prev == NULL ? 0 : tmp->prev->num == (tmp->num - 1));
		}
		printf("Len of list: %zu\n\n", ps_lst_len(*a));
}

int	main(int argc, char **argv)
{
	t_push_swap	*a;

	a = NULL;
	if (1 == argc)
		return (1);
	if (!ps_init_stack_a(argc, argv, &a))
	{
		write(1, "Error\n", 6);
		return (2);
	}
	print_list(&a, 'A');
	ps_lst_free(&a);
	return (0);
}
