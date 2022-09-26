/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:58:05 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:08 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac, char **arr)
{
	int			i;
	long long	atoi_res;

	i = 0;
	while (--ac > 0)
	{
		while (arr[ac][i])
		{
			if (arr[ac][i] == '-')
				i++;
			if (!ft_isdigit(arr[ac][i]))
				return (0);
			i++;
		}
		atoi_res = ft_atoi(arr[ac]);
		if (atoi_res < INT_MIN || atoi_res > INT_MAX)
			return (0);
		i = 0;
	}
	return (1);
}

int	check_doublons(int ac, char **arr, int *tab)
{
	int	i;
	int	j;
	int	nb;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = i;
		nb = ft_atoi(arr[i]);
		while (++j < ac)
		{
			if (nb == ft_atoi(arr[j]))
				return (0);
		}
		i++;
		*tab++ = nb;
	}
	return (1);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	*clone_array(int *tab, int size)
{
	int	i;
	int	*arr_copy;

	i = 0;
	arr_copy = malloc(sizeof(int) * size);
	if (!arr_copy)
		return (NULL);
	while (i < size)
	{
		arr_copy[i] = tab[i];
		i++;
	}
	return (arr_copy);
}

void	assign_index(int *tab, int *copy, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		while (j < ac)
		{
			if (tab[i] == copy[j])
			{
				tab[i] = j;
				break ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
