/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:27:32 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 12:14:05 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_rotate_a(t_deque *deque_a)
{
	t_node	*node_a;

	if (deque_a -> head == deque_a -> tail)
		return ;
	node_a = deque_a -> tail;
	deque_a -> tail = node_a -> prev;
	node_a -> prev -> next = NULL;
	node_a -> prev = NULL;
	deque_a -> head -> prev = node_a;
	node_a -> next = deque_a -> head;
	deque_a -> head = node_a;
}

void	ft_reverse_rotate_b(t_deque *deque_b)
{
	t_node	*node_b;

	if (deque_b -> head == deque_b -> tail)
		return ;
	node_b = deque_b -> tail;
	deque_b -> tail = node_b -> prev;
	node_b -> prev -> next = NULL;
	node_b -> prev = NULL;
	deque_b -> head -> prev = node_b;
	node_b -> next = deque_b -> head;
	deque_b -> head = node_b;
}

void	ft_reverse_rotate_ab(t_deque *deque_a, t_deque *deque_b)
{
	ft_reverse_rotate_a(deque_a);
	ft_reverse_rotate_b(deque_b);
}
