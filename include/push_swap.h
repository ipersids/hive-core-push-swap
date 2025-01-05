/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:21:52 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/05 19:04:38 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/* -------------------------- Errors and Memory ----------------------------- */

void	ps_exit_error(int exit_code);
void	*free_all(void *arr1, void **arr2);

/* ------------------------- Handle input Numbers --------------------------- */

int		*ps_get_numbers(int argc, char **argv, int *dst, int *dst_size);

#endif