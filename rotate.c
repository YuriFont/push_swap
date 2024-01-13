/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:11:32 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/13 17:57:46 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_snode **head)
{
	int		len;
	t_snode	*last_node;

	len = stack_length(*head);
	if (!head || !(*head) || len == 1)
		return ;
	last_node = find_last(*head);
	last_node->next = *head;
	(*head)->prev = last_node;
	*head = (*head)->next;
	last_node->next->next = NULL;
	(*head)->prev = NULL;
}

void	ra(t_snode **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_snode **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_snode **stack_a, t_snode **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
