/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_of_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhamass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:24:54 by akhamass          #+#    #+#             */
/*   Updated: 2024/04/28 15:36:31 by akhamass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_first_greater(t_list *a, int second, int third)
{
	if (second < third)
	{
		ra(a);
	}
	else
	{
		sa(a);
		rra(a);
	}
}

void	sort_second_greater(t_list *a, int first, int third)
{
	if (first < third)
	{
		sa(a);
		ra(a);
	}
	else
	{
		rra(a);
	}
}

void	sort_third_greater(t_list *a, int first, int second)
{
	if (second < first)
	{
		sa(a);
	}
	else
	{
	}
}

void	sort_list_of_three(t_list *a)
{
	int	first;
	int	second;
	int	third;

	first = a->first->nbr;
	second = a->first->next->nbr;
	third = a->first->next->next->nbr;
	if (first > second && first > third)
	{
		sort_first_greater(a, second, third);
	}
	else if (second > first && second > third)
	{
		sort_second_greater(a, first, third);
	}
	else
	{
		sort_third_greater(a, first, second);
	}
}
