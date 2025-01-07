/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:13:35 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 14:14:21 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ps_free_arrays(void *arr1, void **arr2)
{
	int	i;

	if (arr1)
	{
		free(arr1);
		arr1 = NULL;
	}
	if (!arr2)
		return (NULL);
	i = 0;
	while (NULL != arr2[i])
	{
		free(arr2[i]);
		arr2[i] = NULL;
		i++;
	}
	free(arr2);
	arr2 = NULL;
	return (NULL);
}
