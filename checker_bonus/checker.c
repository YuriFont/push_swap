/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:39:03 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/31 18:45:10 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	make_command(t_snode **a, t_snode **b, char *command)
{
	if (!ft_strcmp(command, "sa\n"))
		sa(a);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b);
	else if (!ft_strcmp(command, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(command, "pb\n"))
		pb(b, a);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b);
	else
		exit(1);
}

int	main(void)
{

}
