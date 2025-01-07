/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rank_ascending.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:23:32 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 13:07:25 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Calculate the statistical rank of a given value within an array of values
void	ps_rank_ascending(t_queue *dest, int *src, size_t src_len)
{
	size_t	i;
	size_t	j;
	int		rank;

	i = 0;
	while (i < src_len)
	{
		j = 0;
		rank = 1;
		while (j < src_len)
		{
			if (i != j && src[i] > src[j])
				rank++;
			j++;
		}
		queue_enqueue(dest, rank);
		i++;
	}
}
