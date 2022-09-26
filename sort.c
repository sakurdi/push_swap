/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:58:26 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:33 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(int *tab, int a, int b, int c)
{
	if (tab[0] == a)
	{
		ft_printf("sa\n");
		ft_printf("ra\n");
	}
	else if (tab[0] == b)
	{
		if (tab[1] == a)
			ft_printf("sa\n");
		else
			ft_printf("rra\n");
	}
	else if (tab[0] == c)
	{
		if (tab[1] == a)
			ft_printf("ra\n");
		else
		{
			ft_printf("ra\n");
			ft_printf("sa\n");
		}
	}
}

void	handle_zero(int **tab, int *stack_b, int size)
{
	if ((*tab)[0] == 0)
		*tab = push_b(*tab, stack_b, size, 1);
	else if ((*tab)[1] == 0)
	{
		swap_a(*tab);
		*tab = push_b(*tab, stack_b, size, 1);
	}
	else if ((*tab)[2] == 0)
	{
		rotate_a(*tab, size, 0);
		rotate_a(*tab, size, 0);
		*tab = push_b(*tab, stack_b, size, 1);
	}
	else if ((*tab)[3] == 0)
	{
		reverse_rotate_a(*tab, size);
		reverse_rotate_a(*tab, size);
		*tab = push_b(*tab, stack_b, size, 1);
	}
	else if ((*tab)[4] == 0)
	{
		reverse_rotate_a(*tab, size);
		*tab = push_b(*tab, stack_b, size, 1);
	}
}

void	handle_one(int **tab, int *stack_b, int size)
{
	if ((*tab)[0] == 1)
		*tab = push_b(*tab, stack_b, size, 2);
	else if ((*tab)[1] == 1)
	{
		swap_a(*tab);
		*tab = push_b(*tab, stack_b, size, 2);
	}
	else if ((*tab)[2] == 1)
	{
		rotate_a(*tab, size, 1);
		rotate_a(*tab, size, 1);
		*tab = push_b(*tab, stack_b, size, 2);
	}
	else if ((*tab)[3] == 1)
	{
		reverse_rotate_a(*tab, size - 1);
		*tab = push_b(*tab, stack_b, size, 2);
	}
}

void	sort_five(int **tab, int *stack_b, int size)
{
	handle_zero(tab, stack_b, size);
	handle_one(tab, stack_b, size);
	if (!is_sorted(*tab, size - 2))
		sort_three(*tab, 2, 3, 4);
	ft_printf("pa\n");
	ft_printf("pa\n");
}

int	main(int ac, char **av)
{
	int	*copy;
	int	*tab;
	int	*stack_b;
	int	size;

	if (ac == 1 && ac == 2)
		exit(0);
	size = ac - 1;
	tab = malloc(sizeof(int) * (size));
	init_checks(ac, av, tab);
	stack_b = malloc(sizeof(int) * size);
	copy = clone_array(tab, size);
	load_data(size, tab, copy, stack_b);
	if (size == 2)
		sort_two(tab);
	else if (size == 3)
		sort_three(tab, 0, 1, 2);
	else if (size == 5)
		sort_five(&tab, stack_b, size);
	else
		radix_magic(&tab, stack_b, size);
	free(copy);
	free(stack_b);
	free(tab);
}
