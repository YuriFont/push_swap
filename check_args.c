/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:04:37 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/22 18:00:38 by yufonten         ###   ########.fr       */
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
