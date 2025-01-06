/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:23:46 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/06 14:23:04 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# include "libft.h"

typedef struct s_circ_buf
{
	int		*buf;
	size_t	head;
	size_t	tail;
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

t_bool	cb_init(t_circ_buf *buf, size_t maxlen);
t_bool	cb_fill(t_circ_buf *buf, int *src, size_t src_len);
t_bool	cb_full(const t_circ_buf *buf);
t_bool	cb_empty(const t_circ_buf *buf);
t_bool	cb_put(t_circ_buf *buf, int num);

size_t	cb_next_head(t_circ_buf *buf);
size_t	cb_prev_tail(t_circ_buf *buf);
size_t	cb_get_size(t_circ_buf *buf);
 
/* -------------------------------------------------------------------------- */
/* ------------ src/circular-buffer/circular_buffer_commands.c -------------- */
/* -------------------------------------------------------------------------- */

void	cb_swap(t_circ_buf *buf);
void	cb_push(t_circ_buf *buf);
void	cb_rotate(t_circ_buf *buf);
void	cb_rev_rotate(t_circ_buf *buf);



#endif