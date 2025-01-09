/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:21:52 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 15:12:29 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "circular_buffer.h"
# include "libft.h"

typedef enum e_loc
{
	HEAD_A,
	TAIL_A,
	HEAD_B,
	TAIL_B
}	t_loc;

typedef enum e_command
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
	rrr,
	MAX_COMMANDS
}	t_command;

typedef struct s_storage
{
	int8_t	*list;
	size_t	capacity;
	size_t	len;
}			t_storage;

typedef struct s_partition
{
	t_loc	loc;
	size_t	size;
}			t_partition;

typedef struct s_parts
{
	t_partition	min;
	t_partition	mid;
	t_partition	max;
}				t_parts;

typedef struct s_input
{
	int		*num;
	size_t	len;
}			t_input;

typedef struct s_data
{
	t_queue		a;
	t_queue		b;
	t_storage	command;
	t_input		input;
}				t_data;

void	ps_destroy_data_exit(t_data *data, int exit_code);
void	*ps_free_array(void **arr2);

void	ps_data_init(t_data *data);
int		*ps_get_numbers(int argc, char **argv, int **dst, size_t *dst_size);
void	ps_rank_ascending(t_queue *dest, int *src, size_t src_len);
t_bool	ps_sorted_ascending(const int *src, size_t src_len);
t_bool	ps_stacks_init(t_data *data);

void	ps_save_command(t_data *data, t_command command);
t_bool 	ps_swap_a(t_data *data);
t_bool	ps_swap_b(t_data *data);
t_bool	ps_push_a(t_data *data);
t_bool	ps_push_b(t_data *data);
t_bool	ps_rotate_a(t_data *data);
t_bool	ps_rotate_b(t_data *data);
t_bool	ps_rev_rotate_a(t_data *data);
t_bool	ps_rev_rotate_b(t_data *data);

void	ps_sort(t_data *data, t_partition *this_loc);
void	ps_sort_three(t_data *data, t_partition *this_loc);
void	ps_sort_two(t_data *data, t_partition *this_loc);
void	ps_sort_one(t_data *data, t_partition *this_loc);

void	ps_correct_this_loc(t_data *data, t_partition *this_loc);
void	ps_init_parts(t_parts *part, t_partition *this_loc);

int		ps_read_value(t_data *data, t_partition *this_loc);
int		ps_max_value(t_data *data, t_partition *loc);
t_queue	*ps_which_stack(t_data *data, t_partition *this_loc);
void	ps_print_commands(t_storage *command);

size_t	ps_move_from_to(t_data *data, t_loc this_loc, t_loc dst_loc);

#endif