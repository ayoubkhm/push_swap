/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_four.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhamass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:10:33 by akhamass          #+#    #+#             */
/*   Updated: 2024/04/28 15:14:24 by akhamass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	top_is_second(t_list *a, t_list *b)
{
	pb(a, b);
	sort_list_of_three(a);
	pa(b, a);
	sa(a);
}

void	top_is_third(t_list *a, t_list *b)
{
	sa(a);
	(void)b;
	sort_list_of_four(a);
}

int	find_smallest(t_list *a)
{
	t_element	*current;
	int			smallest;
	int			index_of_smallest;
	int			index;

	if (a == NULL || a->first == NULL)
		return (-1);
	current = a->first;
	smallest = current->nbr;
	index_of_smallest = 0;
	index = 0;
	while (current != NULL)
	{
		if (current->nbr < smallest)
		{
			smallest = current->nbr;
			index_of_smallest = index;
		}
		current = current->next;
		index++;
	}
	return (index_of_smallest);
}

void	sort_list_of_four(t_list *a)
{
	t_list		*b;

	b = initialization(-1);
	if (a->first->nbr == 0)
	{
		pb(a, b);
		sort_list_of_three(a);
		pa(b, a);
	}
	else if (a->first->nbr == 1)
		top_is_second(a, b);
	else if (a->first->nbr == 2)
		top_is_third(a, b);
	else if (a->first->nbr == 3)
	{
		pb(a, b);
		sort_list_of_three(a);
		pa(b, a);
		ra(a);
	}
	sup_all_list(b);
}
