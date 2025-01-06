/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:37:07 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 14:12:41 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

void	cb_swap(t_circ_buf *buf)
{
	if (!buf || cb_empty(buf) || cb_next_indx(buf, buf->head) == buf->tail + 1)
		return ;
	
} 