/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:32:24 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/07 16:15:36 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_snode
{
	int				data;
	int				index;
	int				push_cost;
	struct s_snode	*target_node;
	struct s_snode	*next;
	struct s_snode	*prev;
}	t_snode;

/* STACK_UTILS */

t_snode	*find_last(t_snode *stack);
int		stack_length(t_snode *stack);

#endif
