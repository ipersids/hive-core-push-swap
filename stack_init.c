/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:40:03 by ipersids          #+#    #+#             */
/*   Updated: 2024/12/17 16:04:30 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/* --------------------- Private function prototypes ----------------------- */

static long int	number_check(char *num);
static void		free_all(char **arr, t_push_swap **lst, int allocated);

/* --------------------------- Public Functions ---------------------------- */

/**
 * @brief Initializes stack 'a' with the given arguments.
 * 
 * This function takes the command-line arguments, processes them, and create
 * the stack 'a' with the numbers provided. It handles both single string input
 * and multiple arguments.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param a Pointer to the stack 'a'.
 * @return t_push_swap* Pointer to the initialized stack 'a'. Returns NULL if 
 * 						an error occurs.
 */
t_push_swap	*ps_init_stack_a(int argc, char **argv, t_push_swap **a)
{
	char		**numbers;
	long int	num;
	t_push_swap	*tmp;
	size_t		i;

	numbers = argv + 1;
	if (2 == argc)
		numbers = ft_split(argv[1], ' ');
	if (!numbers)
		return (NULL);
	i = 0;
	while (numbers[i])
	{
		num = number_check(numbers[i]);
		tmp = ps_lst_new(num);
		if (!(INT_MIN <= num && INT_MAX >= num) || !ps_lst_add_back(a, tmp))
		{
			free_all(numbers, a, 2 == argc);
			return (NULL);
		}
		i++;
	}
	free_all(numbers, NULL, 2 == argc);
	return (*a);
}

/* ------------------- Private Function Implementation --------------------- */

/**
 * @brief Checks if the given string is a valid number.
 * 
 * @param num C-string containing the representation of an integral number.
 * @return long int Returns the number as a long int. If the string contains 
 * 					non-digit characters, returns LONG_MAX, which will cause 
 * 					an error in the next steps.
 */
static long int	number_check(char *num)
{
	size_t		i;
	long int	res;

	i = 0;
	while ('\0' != num[i])
	{
		if (!ft_isdigit(num[i]))
			return (LONG_MAX);
		i++;
	}
	res = ft_atol(num);
	return (res);
}

/**
 * @brief Frees an array of strings and a linked list.
 * 
 * @param arr Pointer to the array of strings.
 * @param lst Pointer to the linked list.
 */
static void	free_all(char **arr, t_push_swap **lst, int allocated)
{
	size_t	i;

	ps_lst_free(lst);
	if (!arr || !allocated)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
