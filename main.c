/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhamass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 14:49:51 by akhamass          #+#    #+#             */
/*   Updated: 2024/04/28 17:05:41 by akhamass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	check_input(int ac, char **av)
{
	if (ac < 2)
		return (1);
	if (ac == 2 && av[1][0] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

t_list	*initialize_list(int ac, char **av)
{
	t_list	*a;

	if (ac == 2)
		a = convert_single_string(av[1]);
	else
		a = parsing(0, ac, av, -1);
	return (a);
}

void	process_sorting(t_list *a)
{
	if (a_is_sorted(a) < 0)
	{
		sup_all_list(a);
	}
	else
	{
		if (a->nb_elem <= 5)
			sort_small_stack(a);
		else
			sort_big_stack(a);
		sup_all_list(a);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;

	if (check_input(ac, av) != 0)
		return (1);
	a = initialize_list(ac, av);
	if (a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	process_sorting(a);
	return (0);
}
