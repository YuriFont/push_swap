/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 22:55:56 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/13 23:19:17 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_snode **head)
{
	int		len;
	t_snode	*last_node;

	len = stack_length(*head);
	if (!head || !(*head) || len == 1)
		return ;
	last_node = find_last(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = last_node;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

void	rra(t_snode **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_snode **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_snode **stack_a, t_snode **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_snode **a, t_snode **b, t_snode *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
