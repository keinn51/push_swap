/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:27:43 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 12:14:31 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push_a(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*node_b;

	if (deque_b -> head == NULL)
		return ;
	node_b = deque_b -> head;
	if (node_b -> next)
	{
		node_b -> next -> prev = NULL;
		deque_b -> head = node_b -> next;
	}
	else
	{
		deque_b -> head = NULL;
		deque_b -> tail = NULL;
	}
	node_b -> next = deque_a -> head;
	if (deque_a -> head)
		deque_a -> head -> prev = node_b;
	deque_a -> head = node_b;
	if (!deque_a -> tail)
		deque_a -> tail = node_b;
	ft_renew_lstsize(deque_a, deque_b);
}

void	ft_push_b(t_deque *deque_a, t_deque *deque_b)
{
	t_node	*node_a;

	if (deque_a -> head == NULL)
		return ;
	node_a = deque_a -> head;
	if (node_a -> next)
	{
		node_a -> next -> prev = NULL;
		deque_a -> head = node_a -> next;
	}
	else
	{
		deque_a -> head = NULL;
		deque_a -> tail = NULL;
	}
	node_a -> next = deque_b -> head;
	if (deque_b -> head)
		deque_b -> head -> prev = node_a;
	deque_b -> head = node_a;
	if (!deque_b -> tail)
		deque_b -> tail = node_a;
	ft_renew_lstsize(deque_a, deque_b);
}
