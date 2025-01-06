/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:51:42 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 14:22:00 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circular_buffer.h"

/**
 * @brief Initializes a circular buffer.
 * 
 * This function initializes a circular buffer with a given maximum length.
 * It allocates memory for the buffer and sets the read and write indices to 0.
 * 
 * @param buf Pointer to the circular buffer structure.
 * @param maxlen Maximum length of the circular buffer.
 * @return t_bool Returns TRUE (1) if the buffer is successfully initialized, 
 * 				  FALSE (0) otherwise.
 */
t_bool	cb_init(t_circ_buf *buf, size_t maxlen)
{
	if (!buf || 0 == maxlen)
		return (FALSE);
	buf->buf = (int *) ft_calloc(maxlen, sizeof(int));
	if (!buf->buf)
		return (FALSE);
	buf->head = 0;
	buf->tail = 0;
	buf->maxlen = maxlen;
	return (TRUE);
}

/**
 * @brief Fills a circular buffer with data from a source array.
 * 
 * This function fills a circular buffer with data from a given source array.
 * It iterates through the source array and puts each element into the buffer.
 * 
 * @param buf Pointer to the circular buffer structure.
 * @param src Pointer to the source array.
 * @param src_len Length of the source array.
 * @return t_bool Returns TRUE if the buffer is successfully filled, 
 * 				  FALSE otherwise.
 */
t_bool	cb_fill(t_circ_buf *buf, int *src, size_t src_len)
{
	size_t	i;

	if (!buf || !src || 0 == src_len)
		return (FALSE);
	i = 0;
	while (src_len > i)
	{
		if (!cb_put(buf, src[i]))
			return (FALSE);
		ft_printf("%d [%d -> %d], ", src[i], (int)i, (int)buf->tail);
		i++;
	}
	return (TRUE);
}

/**
 * @brief Checks if a circular buffer is full.
 * 
 * @param buf Pointer to the circular buffer structure.
 * @return t_bool Returns TRUE if the buffer is full, FALSE otherwise.
 */
t_bool	cb_full(const t_circ_buf *buf)
{
	return ((buf->tail + 1) % buf->maxlen == buf->head);
}

/**
 * @brief Checks if a circular buffer is empty.
 * 
 * @param buf Pointer to the circular buffer structure.
 * @return t_bool Returns TRUE if the buffer is empty, FALSE otherwise.
 */
t_bool	cb_empty(const t_circ_buf *buf)
{
	return (buf->tail == buf->head);
}

/**
 * @brief Puts an element into the circular buffer.
 * 
 * This function adds an element to the circular buffer. If the buffer is full,
 * it will not add the element and will return FALSE.
 * 
 * @param buf Pointer to the circular buffer structure.
 * @param num The element to be added to the buffer.
 * @return t_bool Returns TRUE if the element is successfully added, 
 * 				  FALSE if the buffer is full.
 */
t_bool	cb_put(t_circ_buf *buf, int num)
{
	if (cb_full(buf))
		return (FALSE);
	buf->buf[buf->tail] = num;
	buf->tail = (buf->tail + 1) % buf->maxlen;
	return (TRUE);
}

size_t	cb_next_head(t_circ_buf *buf)
{
	size_t	next;

	next = (buf->head + 1) % buf->maxlen;
	return (next);
}
