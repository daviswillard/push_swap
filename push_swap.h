/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:00:32 by dwillard          #+#    #+#             */
/*   Updated: 2021/08/18 11:00:34 by dwillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

t_stack *get_args(int argc, char **argv);

void	swap(t_stack **lst);

void	push(t_stack **lst_a, t_stack **lst_b);

void	rotate(t_stack **lst_a);

void	r_rotate(t_stack **lst);

#endif
