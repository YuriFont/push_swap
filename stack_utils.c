/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:06:44 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/15 20:25:05 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_snode	*find_last(t_snode *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	stack_length(t_snode *head)
{
	int	len;

	if (!head)
		return (0);
	len = 0;
	while (head)
	{
		len++;
		head = head->next;
	}
	return (len);
}

int	sorted_stack(t_snode *head)
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}

t_snode	*find_min_node(t_snode *head)
{
	long	min;
	t_snode	*min_node;

	if (!head)
		return (NULL);
	min = LONG_MAX;
	while (head->next)
	{
		if (head->data < min)
		{
			min = head->data;
			min_node = head;
		}
		head = head->next;
	}
	return (min_node);
}

t_snode	*find_max_node(t_snode *head)
{
	long	max;
	t_snode	*max_node;

	if (!head)
		return (NULL);
	max = LONG_MIN;
	while (head->next)
	{
		if (head->data > max)
		{
			max = head->data;
			max_node = head;
		}
		head = head->next;
	}
	return (max_node);
}
