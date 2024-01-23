/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:04:37 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 02:35:24 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parameter_error(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '+' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
		return (true);
	if ((str[i] == '+' || str[i] == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (true);
	while (str[++i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (true);
	}
	return (false);
}

bool	repeated_number(t_snode *head, int nbr)
{
	if (head == NULL)
		return (false);
	while (head)
	{
		if (head->data == nbr)
			return (true);
		head = head->next;
	}
	return (false);
}
