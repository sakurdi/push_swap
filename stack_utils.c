/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:58:52 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:54 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ptr(int *ptr)
{
	if (!ptr)
		exit(EXIT_FAILURE);
}

void	swap_a(int *tab)
{	
	int	temp;

	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
	ft_printf("sa\n");
}

void	sort_two(int *tab)
{
	swap_a(tab);
}

void	reverse_rotate_a(int *stack_a, int a_size)
{
	int	temp;
	int	i;
	int	size;

	i = 0;
	size = a_size - 1;
	temp = stack_a[size];
	while (size >= 1)
	{
		stack_a[size] = stack_a[size - 1];
		i++;
		size--;
	}
	stack_a[0] = temp;
	ft_printf("rra\n");
}

int	is_sorted(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
