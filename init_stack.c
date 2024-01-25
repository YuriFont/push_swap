/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:49:20 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 15:13:32 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * sign);
}

static void	append_node(t_snode **stack, int n)
{
	t_snode	*node;
	t_snode	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_snode));
	if (!node)
		return ;
	node->next = NULL;
	node->data = n;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_snode **stack_a, char **av, bool argc_2)
{
	int		i;
	long	n;

	i = 0;
	while (av[i] != NULL)
	{
		if (parameter_error(av[i]))
			error_free(stack_a, av, argc_2);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_free(stack_a, av, argc_2);
		if (repeated_number(*stack_a, (int)n))
			error_free(stack_a, av, argc_2);
		append_node(stack_a, (int)n);
		i++;
	}
}

void	prep_for_push(t_snode **head, t_snode *cheapest_node, char name_stack)
{
	while (*head != cheapest_node)
	{
		if (name_stack == 'a')
		{
			if (cheapest_node->above_median)
				ra(head);
			else
				rra(head);
		}
		else if (name_stack == 'b')
		{
			if (cheapest_node->above_median)
				rb(head);
			else
				rrb(head);
		}
	}
}
