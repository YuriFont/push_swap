/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:39:03 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/31 19:04:15 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap/push_swap.h"
#include "get_next_line.h"

void	final_free(t_snode **stack_a, char **av, bool argc_2)
{
	free_stack(stack_a);
	if (argc_2)
		free_matrix(av);
}

int	main(int ac, char **av)
{
	t_snode	*a;
	t_snode	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av++;
	init_stack(&a, av, ac == 2);
	if (!sorted_stack(a))
	{
		if (stack_length(a) == 2)
			sa(&a);
		else if (stack_length(a) == 3)
			sorted_three(&a);
		else
			sorted_algorithm(&a, &b);
	}
	final_free(&a, av, ac == 2);
	return (0);
}
