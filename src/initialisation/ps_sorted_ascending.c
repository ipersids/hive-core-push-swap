/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorted_ascending.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:27:27 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 14:40:48 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ps_sorted_ascending(const int *src, size_t src_len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < src_len)
	{
		j = i + 1;
		while (j < src_len)
		{
			if (src[i] > src[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
