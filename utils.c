/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:58:58 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/09/26 11:59:03 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long long	ft_atoi(const char *s)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		res = res * 10 + (*s++ - '0');
	return (res * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

void	load_data(int size, int *tab, int *copy, int *stack_b)
{
	if (!copy || !stack_b)
		exit(0);
	sort_tab(copy, size);
	assign_index(tab, copy, size);
	if (is_sorted(tab, size))
	{
		free(tab);
		free(copy);
		free(stack_b);
		exit(0);
	}
}

void	init_checks(int ac, char **av, int *tab)
{
	if (!tab)
		exit(0);
	if (!check_args(ac, av))
	{
		free(tab);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	else if (!check_doublons(ac, av, tab))
	{
		free(tab);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}
