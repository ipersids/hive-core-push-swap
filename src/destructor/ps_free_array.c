/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 19:13:35 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 13:50:21 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ps_free_array(void **arr2)
{
	int	i;

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
