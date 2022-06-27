/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:33 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/10 19:23:59 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_deque *deque_a)
{
	t_node	*node;
	int		check_index;

	if (!deque_a -> head)
		return (0);
	node = deque_a -> head;
	check_index = deque_a -> head -> index;
	while (node != NULL)
	{
		if (check_index != node -> index)
			return (0);
		node = node -> next;
		check_index++;
	}
	return (1);
}

t_deque	*ft_deqnew(t_deque *lst)
{
	lst = (t_deque *)malloc(sizeof(t_deque));
	if (lst == NULL)
		exit (1);
	lst->size = 0;
	lst -> head = NULL;
	lst -> tail = NULL;
	return (lst);
}

void	ft_alloc_deq(t_deque **deque_a, t_deque **deque_b)
{
	*deque_a = ft_deqnew(*deque_a);
	*deque_b = ft_deqnew(*deque_b);
}
