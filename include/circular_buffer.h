/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:23:46 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/05 22:09:47 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# include "libft.h"

typedef struct s_circ_buf
{
	int		*buf;
	size_t	read;
	size_t	write;
	size_t	maxlen;
}			t_circ_buf;

enum	e_command
{
	do_nothing,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

/* -------------------------------------------------------------------------- */
/* ------------- src/circular-buffer/circular_buffer_utils.c ---------------- */
/* -------------------------------------------------------------------------- */

/**
 * @brief Initializes a circular buffer.
 * 
 * This function initializes a circular buffer with a given maximum length.
 * It allocates memory for the buffer and sets the read and write indices to 0.
 * 
 * @param buffer Pointer to the circular buffer structure.
 * @param maxlen Maximum length of the circular buffer.
 * @return t_bool Returns TRUE (1) if the buffer is successfully initialized, 
 * 				  FALSE (0) otherwise.
 */
t_bool	circular_buf_init(t_circ_buf *buffer, size_t maxlen);

/**
 * @brief Fills a circular buffer with data from a source array.
 * 
 * This function fills a circular buffer with data from a given source array.
 * It iterates through the source array and puts each element into the buffer.
 * 
 * @param buffer Pointer to the circular buffer structure.
 * @param src Pointer to the source array.
 * @param src_len Length of the source array.
 * @return t_bool Returns TRUE if the buffer is successfully filled, 
 * 				  FALSE otherwise.
 */
t_bool	circular_buf_fill(t_circ_buf *buffer, int *src, size_t src_len);

/**
 * @brief Checks if a circular buffer is full.
 * 
 * @param buffer Pointer to the circular buffer structure.
 * @return t_bool Returns TRUE if the buffer is full, FALSE otherwise.
 */
t_bool	circular_buf_full(const t_circ_buf *buffer);

/**
 * @brief Puts an element into the circular buffer.
 * 
 * This function adds an element to the circular buffer. If the buffer is full,
 * it will not add the element and will return FALSE.
 * 
 * @param buffer Pointer to the circular buffer structure.
 * @param num The element to be added to the buffer.
 * @return t_bool Returns TRUE if the element is successfully added, 
 * 				  FALSE if the buffer is full.
 */
t_bool	circular_buf_put(t_circ_buf *buffer, int num);
 
#endif