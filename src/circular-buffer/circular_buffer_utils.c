/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:51:42 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/05 23:36:40 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

t_bool	circular_buf_init(t_circ_buf *buffer, size_t maxlen)
{
	if (!buffer || 0 == maxlen)
		return (FALSE);
	buffer->buf = (int *) ft_calloc(maxlen, sizeof(int));
	if (!buffer->buf)
		return (FALSE);
	buffer->read = 0;
	buffer->write = 0;
	buffer->maxlen = maxlen;
	return (TRUE);
}

t_bool	circular_buf_fill(t_circ_buf *buffer, int *src, size_t src_len)
{
	size_t	i;

	if (!buffer || !src || 0 == src_len)
		return (FALSE);
	i = 0;
	while (src_len > i)
	{
		if (!circular_buf_put(buffer, src[i]))
			return (FALSE);
		ft_printf("%d [%d -> %d], ", src[i], (int)i, (int)buffer->write);
		i++;
	}
	return (TRUE);
}

t_bool	circular_buf_full(const t_circ_buf *buffer)
{
	return (buffer->write == buffer->read);
}

t_bool	circular_buf_put(t_circ_buf *buffer, int num)
{
	buffer->buf[buffer->write] = num;
	buffer->write = (buffer->write + 1) % buffer->maxlen;
	return (TRUE);
}
