/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:13:16 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/10 16:25:16 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_snode **head)
{
	int	len;

	len = stack_length(*head);
	if (NULL == *head || NULL == head || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_snode **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_snode **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_snode **stack_a, t_snode **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
