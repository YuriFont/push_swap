/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:49:20 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/15 20:46:17 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	n;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45)
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == 43)
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

void	init_stack(t_snode **stack_a, char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i] != NULL)
	{
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			break ;
		append_node(stack_a, (int)n);
		i++;
	}
}
