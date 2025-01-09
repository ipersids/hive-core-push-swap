/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_get_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:34:40 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 16:32:59 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------- Private function prototypes ----------------------- */

static char		*create_list_from_input(char **list, int size);
static int		*handle_list_input(char *list, int **dst, size_t *dst_size);
static t_bool	is_number_valid(const char *str, int *dst, int indx);
static t_bool	is_number_duplicate(int num, int *dst, int dst_size);

/* --------------------------- Public Functions ---------------------------- */

int	*ps_get_numbers(int argc, char **argv, int **dst, size_t *dst_size)
{
	char	*tmp;

	if (2 == argc)
		return (handle_list_input(argv[1], dst, dst_size));
	if (2 < argc)
	{
		tmp = create_list_from_input(argv + 1, argc - 1);
		*dst = handle_list_input(tmp, dst, dst_size);
		free(tmp);
		return (*dst);
	}
	return (NULL);
}

/* ------------------- Private Function Implementation --------------------- */

static char	*create_list_from_input(char **list, int size)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	i = size - 1;
	while (0 <= i)
		len += ft_strlen(list[i--]) + 1;
	res = (char *) malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	len = 0;
	while (i < size)
	{
		while ('\0' != *list[i])
		{
			res[len++] = *list[i];
			list[i]++;
		}
		res[len++] = ' ';
		i++;
	}
	res[len] = '\0';
	return (res);
}

static int	*handle_list_input(char *list, int **dst, size_t *dst_size)
{
	char	**temp_arr;
	int		i;

	if (!list)
		return (NULL);
	temp_arr = ft_split(list, ' ');
	if (!temp_arr)
		return (NULL);
	*dst_size = 0;
	while (NULL != temp_arr[*dst_size])
		*dst_size += 1;
	*dst = (int *) malloc(*dst_size * sizeof(int));
	if (!*dst)
		return (ps_free_array((void **)temp_arr));
	i = 0;
	while (NULL != temp_arr[i])
	{
		if (!is_number_valid(temp_arr[i], *dst, i))
			return (ps_free_array((void **)temp_arr));
		(*dst)[i] = ft_atoi(temp_arr[i]);
		i++;
	}
	ps_free_array((void **)temp_arr);
	return (*dst);
}

static t_bool	is_number_valid(const char *str, int *dst, int indx)
{
	int			i;
	long int	num;

	i = 0;
	while ('\0' != str[i])
	{
		if (0 == i && ('-' == str[i] || '+' == str[i]))
		{
			i++;
			continue ;
		}
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	num = ft_atol(str);
	if (INT_MIN > num || INT_MAX < num)
		return (FALSE);
	if (is_number_duplicate((int)num, dst, indx))
		return (FALSE);
	return (TRUE);
}

static t_bool	is_number_duplicate(int num, int *dst, int dst_size)
{
	int	i;

	i = 0;
	while (dst_size > i)
	{
		if (dst[i] == num)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
