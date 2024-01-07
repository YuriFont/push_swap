/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:06:44 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/07 16:15:39 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_snode	*find_last(t_snode *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_length(t_snode *stack)
{
	int	len;

	if (!stack)
		return (0);
	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}


