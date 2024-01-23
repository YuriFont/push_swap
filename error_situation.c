/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_situation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:05:39 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 02:36:35 by yufonten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_snode **head)
{
	t_snode	*tmp;
	t_snode	*release;

	if (!head == NULL)
		return ;
	release = *head;
	while (release)
	{
		tmp = release->next;
		free(release);
		release = tmp;
	}
	*head = NULL;
}

void	free_matrix(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	error_free(t_snode **head, char **av, bool argc_2)
{
	free_stack(head);
	if (argc_2)
		free_matrix(av);
	write(2, "Error\n", 6);
	exit(1);
}
