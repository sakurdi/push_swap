/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:58:44 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:45 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_a(int *stack_a, int a_size, int b_size)
{
	int	temp;
	int	i;

	i = 0;
	if (a_size - b_size <= 1)
	{
		ft_printf("ra\n");
		return ;
	}
	temp = stack_a[0];
	while (i < (a_size - b_size) - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = temp;
	ft_printf("ra\n");
}

int	*push_b(int *stack_a, int *stack_b, int a_size, int b_size)
{
	int	i;
	int	*new_a;

	i = 0;
	check_ptr(stack_a);
	stack_b[b_size - 1] = stack_a[0];
	new_a = malloc(sizeof(int) * (a_size - b_size));
	if (!new_a)
		return (NULL);
	while (i < a_size - b_size)
	{
		new_a[i] = stack_a[i + 1];
		i++;
	}
	free(stack_a);
	ft_printf("pb\n");
	return (new_a);
}

int	*connect(int *stack_a, int *stack_b, int a_size, int b_size)
{
	int	i;
	int	j;
	int	*connect;

	i = 0;
	j = b_size;
	check_ptr(stack_a);
	connect = malloc(sizeof(int) * a_size);
	if (!connect)
		return (NULL);
	while (--j >= 0)
	{
		connect[j] = stack_b[j];
		i++;
		ft_printf("pa\n");
	}
	j = 0;
	while (j < a_size - b_size)
	{
		connect[i] = stack_a[j];
		i++;
		j++;
	}
	free(stack_a);
	return (connect);
}

void	init_values(int *i, int *j, int *bits, int *b_push)
{
	*i = 0;
	*j = 0;
	*bits = 0;
	*b_push = 0;
}

void	radix_magic(int **tab, int *stack_b, int tab_size)
{
	int	i;
	int	j;
	int	bits;
	int	b_push;

	init_values(&i, &j, &bits, &b_push);
	while (((tab_size - 1) >> bits) != 0)
		bits++;
	while (i < bits)
	{
		while (j < tab_size)
		{
			if ((((*tab)[0] >> i) & 1))
				rotate_a(*tab, tab_size, b_push);
			else
				*tab = push_b(*tab, stack_b, tab_size, ++b_push);
			j++;
		}
		*tab = connect(*tab, stack_b, tab_size, b_push);
		j = 0;
		b_push = 0;
		i++;
	}
}
