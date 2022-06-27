/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:43 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 13:41:57 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	b_rr(t_deque *deque_b, int *position, int *top_num)
{
	ft_reverse_rotate_b(deque_b);
	*top_num = deque_b -> head -> index;
	(*position)++;
}

void	b_r(t_deque *deque_b, int *position, int *top_num)
{
	ft_rotate_b(deque_b);
	*top_num = deque_b -> head -> index;
	(*position)--;
}

void	find_big_idx(t_node *node, int *size, int *big_idx)
{
	while (node != NULL)
	{
		if (node -> index == (*size) - 1)
			break ;
		(*big_idx)++;
		node = node -> next;
	}
}

void	b_to_a(t_deque *deque_a, t_deque *deque_b)
{
	int		top_num;
	int		mid_num;
	int		big_idx;
	int		size;
	t_node	*node;

	size = deque_b -> size;
	while (size > 0)
	{
		big_idx = 0;
		node = deque_b -> head;
		top_num = deque_b -> head -> index;
		find_big_idx(node, &size, &big_idx);
		mid_num = size / 2;
		if (big_idx > mid_num)
			while (big_idx < size)
				b_rr(deque_b, &big_idx, &top_num);
		else if (big_idx <= mid_num)
			while (big_idx > 0)
				b_r(deque_b, &big_idx, &top_num);
		ft_push_a(deque_a, deque_b);
		size--;
	}
}
