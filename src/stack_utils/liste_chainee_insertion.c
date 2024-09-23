/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_chainee_insertion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhamass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:40:56 by akhamass          #+#    #+#             */
/*   Updated: 2024/04/28 15:40:58 by akhamass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	mid_insertion(t_list *list, t_element *element, int nw_nbr)
{
	t_element	*actuel;
	t_element	*new;

	new = malloc(sizeof(*new));
	if (list == NULL || new == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	actuel = list->first;
	while (actuel != element)
		actuel = actuel->next;
	if (actuel == element)
	{
		new->nbr = nw_nbr;
		new->next = actuel->next;
		actuel->next = new;
		list->nb_elem++;
	}
	else
		return (0);
	return (0);
}

t_list	*initialization(int nbr)
{
	t_element	*element;
	t_list		*list;

	list = malloc(sizeof(*list));
	element = malloc(sizeof(*element));
	if (list == NULL || element == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	element->nbr = nbr;
	element->next = NULL;
	list->first = element;
	list->nb_elem = 1;
	return (list);
}

int	insertion(t_list *list, int nvnbr)
{
	t_element	*new;

	new = malloc(sizeof(*new));
	if (list == NULL || new == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	new->nbr = nvnbr;
	new->next = list->first;
	list->first = new;
	list->nb_elem++;
	return (0);
}
