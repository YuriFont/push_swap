/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:32:24 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/13 17:46:01 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_snode
{
	int				data;
	struct s_snode	*next;
	struct s_snode	*prev;
}	t_snode;

/* STACK_UTILS */

t_snode	*find_last(t_snode *stack);
t_snode	*min_node(t_snode *stack);
t_snode	*max_node(t_snode *stack);
int		stack_length(t_snode *stack);
int		sorted_stack(t_snode *stack);

/* Stack operations */

void	swap(t_snode **head);
void	sa(t_snode **stack_a);
void	sb(t_snode **stack_b);
void	ss(t_snode **stack_a, t_snode **stack_b);
void	push(t_snode **receive, t_snode **loss);
void	pa(t_snode **stack_a, t_snode **stack_b);
void	pb(t_snode **stack_b, t_snode **stack_a);
void	rotate(t_snode **head);
void	ra(t_snode **stack_a);
void	rb(t_snode **stack_b);
void	rr(t_snode **stack_a, t_snode **stack_b);

#endif
