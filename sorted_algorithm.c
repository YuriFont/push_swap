/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:16:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 19:10:01 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_a_to_b(t_snode **stack_a, t_snode **stack_b)
{
	t_snode	*cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, 'a');
	prep_for_push(stack_b, cheapest_node->target_node, 'b');
	pb(stack_b, stack_a);
}

static void	move_b_to_a(t_snode **stack_a, t_snode **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}

static void	min_on_top(t_snode **stack_a)
{
	while ((*stack_a)->data != find_min_node(*stack_a)->data)
	{
		if (find_min_node(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sorted_algorithm(t_snode **stack_a, t_snode **stack_b)
{
	int	len_a;

	len_a = stack_length(*stack_a);
	if (len_a-- > 3 && !sorted_stack(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !sorted_stack(*stack_a))
		pb(stack_b, stack_a);
	while (len_a-- > 3 && !sorted_stack(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sorted_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
