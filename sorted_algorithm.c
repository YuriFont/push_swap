/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:16:11 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 17:12:09 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted_algorithm(t_snode **stack_a, t_snode **stack_b)
{
	t_snode	*min;
	t_snode	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		tmp = *stack_a;
		min = find_min_node(*stack_a);
		while (tmp != min && tmp != NULL && stack_length(*stack_a) != 1)
		{
			tmp = tmp->next;
			ra(stack_a);
		}
		if (stack_length(*stack_a) != 0)
			pb(stack_b, stack_a);
	}
	tmp = *stack_b;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		pa(stack_a, stack_b);
	}
}
