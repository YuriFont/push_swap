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

#include "push_swap.c"

void	current_index(t_snode *head)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	median = stack_length(head) / 2;
	i = 0;
	while (head)
	{
		head->index = i;
		if (i <= median)
			head->above = true;
		else
			head->above = false;
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
			if (current_b->data < stack_a->data && current_b->data > best_match_index)
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