/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sal-kurd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:58:18 by sal-kurd          #+#    #+#             */
/*   Updated: 2022/09/26 11:58:20 by sal-kurd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

long long	ft_atoi(const char *s);
size_t		ft_printf(char *s, ...);
int			*clone_array(int *tab, int size);
int			*connect(int *stack_a, int *stack_b, int a_size, int b_size);
int			*push_b(int *stack_a, int *stack_b, int a_size, int b_size);
int			ft_isdigit(int c);
int			check_args(int ac, char **arr);
int			check_doublons(int ac, char **arr, int *tab);
int			is_sorted(int *tab, int size);
int			is_sorted(int *tab, int size);
void		swap_a(int *tab);
void		assign_index(int *tab, int *copy, int ac);
void		radix_magic(int **tab, int *stack_b, int tab_size);
void		rotate_a(int *stack_a, int a_size, int b_size);
void		reverse_rotate_a(int *stack_a, int a_size);
void		sort_tab(int *tab, int size);
void		sort_two(int *tab);
void		ft_putstr_fd(char *s, int fd);
void		init_checks(int ac, char **av, int *tab);
void		load_data(int size, int *tab, int *copy, int *stack_b);
void		reverse_rotate_a(int *stack_a, int a_size);
void		check_ptr(int *ptr);

#endif