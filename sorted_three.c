/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:28:56 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/15 15:45:59 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sorted_three(t_snode **stack_a)
{
    t_snode *max_node;

    max_node = find_max_node(*stack_a);
    if (*stack_a == max_node)
        ra(stack_a);
    else if ((*stack_a)->next == max_node)
        rra(stack_a);
    if ((*stack_a)->data > (*stack_a)->next->data)
        sa(stack_a);
}