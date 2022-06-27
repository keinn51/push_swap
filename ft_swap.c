/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:40:44 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/08 02:52:10 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_deque *deque_a)
{	
	t_node	*curr;

	if (deque_a -> head == deque_a -> tail)
		return ;
	curr = deque_a -> head;
	curr -> next -> prev = NULL;
	curr -> prev = curr -> next;
	curr -> next = curr -> next -> next;
	curr -> prev -> next = curr;
	if (curr -> next)
		curr -> next -> prev = curr;
	deque_a -> head = curr -> prev;
	if (deque_a -> head == deque_a -> tail)
		deque_a -> tail = curr;
	ft_putstr_fd("sa\n", 1);
}

void	ft_swap_b(t_deque *deque_b)
{	
	t_node	*curr;

	if (deque_b -> head == deque_b -> tail)
		return ;
	curr = deque_b -> head;
	curr -> next -> prev = NULL;
	curr -> prev = curr -> next;
	curr -> next = curr -> next -> next;
	curr -> prev -> next = curr;
	if (curr -> next)
		curr -> next -> prev = curr;
	deque_b -> head = curr -> prev;
	if (deque_b -> head == deque_b -> tail)
		deque_b -> tail = curr;
	ft_putstr_fd("sb\n", 1);
}

void	ft_swap_ab(t_deque *deque_a, t_deque *deque_b)
{
	ft_swap_a(deque_a);
	ft_swap_b(deque_b);
	ft_putstr_fd("ss\n", 1);
}
