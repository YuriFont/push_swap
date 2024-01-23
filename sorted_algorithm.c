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

void	sorted_algorithm(t_snode **stack_a, t_snode **stack_b)
{
	t_snode	*tmp;

	while (*stack_a != NULL)
	{
		tmp = find_min_node(*stack_a);
		while (*stack_a != tmp)
		{
			ra(stack_a);
		}
		if (stack_length(*stack_a) > 0)
			pb(stack_b, stack_a);
	}
	while (*stack_b != NULL)
	{
		pa(stack_a, stack_b);
	}
}
