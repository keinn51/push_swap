/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:41:35 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 12:10:46 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_size_three(t_deque *deque_a)
{
	while (deque_a -> tail -> index != 2)
		ft_rotate_a(deque_a);
	if (check_sorted(deque_a))
		return ;
	else
		ft_swap_a(deque_a);
}

void	sort_size_five(t_deque *deque_a, t_deque *deque_b, int *zero_idx)
{
	if (*zero_idx > 2)
		while (deque_a -> head -> index != 0)
			ft_reverse_rotate_a(deque_a);
	else if (*zero_idx <= 2)
		while (deque_a -> head -> index != 0)
			ft_rotate_a(deque_a);
	ft_push_b(deque_a, deque_b);
	while (deque_a -> head -> index != 1)
		ft_rotate_a(deque_a);
	ft_push_b(deque_a, deque_b);
	while (deque_a -> tail -> index != 4)
		ft_rotate_a(deque_a);
	if (!check_sorted(deque_a))
		ft_swap_a(deque_a);
	ft_push_a(deque_a, deque_b);
	ft_push_a(deque_a, deque_b);
}

void	sort_small_size(t_deque *deque_a, t_deque *deque_b, int size)
{
	int		zero_idx;
	t_node	*node;

	node = deque_a -> head;
	zero_idx = 0;
	if (size == 2)
		ft_rotate_a(deque_a);
	else if (size == 3)
		sort_size_three(deque_a);
	else if (size == 5)
	{
		while (node -> index)
		{
			zero_idx++;
			node = node -> next;
		}
		sort_size_five(deque_a, deque_b, &zero_idx);
	}
}
