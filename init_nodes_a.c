/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:17:48 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/25 10:17:50 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_snode *head)
{
	int	i;
	int	median;

	if (!head)
		return ;
	median = stack_length(head) / 2;
	i = 0;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above_median = true;
		else
			head->above_median = false;
		head = head->next;
		i++;
	}
}

static void	set_target_a(t_snode *stack_a, t_snode *stack_b)
{
	t_snode	*target_node;
	t_snode	*current_b;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->data < stack_a->data
				&& current_b->data > best_match_index)
			{
				best_match_index = current_b->data;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = find_max_node(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	push_cost_a(t_snode *stack_a, t_snode *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = stack_length(stack_a);
	len_b = stack_length(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_snode *head)
{
	t_snode	*cheapest;
	long	most_cheapest;

	if (!head)
		return ;
	most_cheapest = LONG_MAX;
	while (head)
	{
		if (head->push_cost < most_cheapest)
		{
			cheapest = head;
			most_cheapest = head->push_cost;
		}
		head = head->next;
	}
	cheapest->cheapest = true;
}

void	init_nodes_a(t_snode *stack_a, t_snode *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	push_cost_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
