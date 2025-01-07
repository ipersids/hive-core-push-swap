/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_buffer.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 20:23:46 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/07 16:45:20 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CIRCULAR_BUFFER_H
# define CIRCULAR_BUFFER_H

# include "libft.h"

typedef struct s_queue
{
	int		*buf;
	size_t	read;
	size_t	write;
	size_t	size;
	size_t	len;
}			t_queue;

t_bool	queue_init(t_queue *stack, size_t maxlen);
t_bool	queue_full(t_queue *stack);
t_bool	queue_empty(t_queue *stack);
t_bool	queue_enqueue(t_queue *stack, int num);
int		queue_dequeue(t_queue *stack);
t_bool	queue_add_vip(t_queue *stack, int num);
int		queue_remove_last(t_queue *stack);
void	queue_free(t_queue *stack);

#endif