/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_situation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufonten <yufonten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 02:05:39 by yufonten          #+#    #+#             */
/*   Updated: 2024/01/23 02:29:52 by yufonten         ###   ########.fr       */
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
