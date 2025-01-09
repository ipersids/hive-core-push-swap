/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:51:53 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/09 20:46:59 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	checker_is_presorted(t_data *data, char *line);
void	checker_do_command(t_data *data, char *line);
void	checker_is_aftersorted(t_data *data);

#endif