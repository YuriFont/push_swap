/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:16:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 15:08:31 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorted_algorithm(t_snode **stack_a, t_snode **stack_b)
{
	t_snode	*min;
	t_snode	*tmp1;
	t_snode	*tmp2;

	tmp1 = *stack_a;
	while (tmp1 != NULL)
	{
		tmp1 = *stack_a;
		min = find_min_node(*stack_a);
		while (tmp1 != min && tmp1 != NULL)
		{
			tmp1 = tmp1->next;
			ra(stack_a);
		}
		pb(stack_b, stack_a);
	}
	tmp2 = *stack_b;
	while (tmp2 != NULL)
	{
		tmp2 = tmp2->next;
		pa(stack_a, stack_b);
	}
}