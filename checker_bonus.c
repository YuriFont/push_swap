/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:39:03 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/31 19:38:20 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_free(t_snode **stack_a, char **av, bool argc_2)
{
	free_stack(stack_a);
	if (argc_2)
		free_matrix(av);
}

void	choosing_algorithm(t_snode **a, t_snode **b)
{
	if (stack_length(*a) == 2)
		sa(a);
	else if (stack_length(*a) == 3)
		sorted_three(a);
	else
		sorted_algorithm(a, b);
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
		choosing_algorithm(&a, &b);
	}
	if (sorted_stack(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	final_free(&a, av, ac == 2);
	return (0);
}
