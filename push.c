/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:05:35 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/10 15:56:25 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_snode **receive, t_snode **loss)
{
	t_snode	*node_push;

	if (!*loss)
		return ;
	node_push = *loss;
	*loss = (*loss)->next;,
	if (*loss)
		(*loss)->prev = NULL;
	node_push->prev = NULL;
	if (*receive)
	{
		node_push->next = *receive;
		*receive->prev = node_push;
		*receive = node_push;
	}
	else
	{
		*receive = node_push;
		(*receive)->next = NULL;
	}
}

void	pa(t_snode **stack_a, t_snode **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_snode **stack_b, t_snode **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
