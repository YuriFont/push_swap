/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:32:24 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 02:36:56 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_snode
{
	int				data;
	struct s_snode	*next;
	struct s_snode	*prev;
}	t_snode;

/* STACK_UTILS */

t_snode	*find_last(t_snode *head);
t_snode	*find_min_node(t_snode *head);
t_snode	*find_max_node(t_snode *head);
int		stack_length(t_snode *head);
int		sorted_stack(t_snode *head);
void	init_stack(t_snode **stack_a, char **av, bool argc_2);
long	ft_atol(const char *str);

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

void	reverse_rotate(t_snode **head);
void	rra(t_snode **stack_a);
void	rrb(t_snode **stack_b);
void	rrr(t_snode **stack_a, t_snode **stack_b);

/* Check Args */
bool	parameter_error(char *str);
bool	repeated_number(t_snode *head, int nbr);

/* Error Situation */
void	free_stack(t_snode **head);
void	free_matrix(char **av);

/* A S */
void	sorted_three(t_snode **stack_a);

#endif
