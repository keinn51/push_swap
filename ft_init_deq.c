/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_deq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:27 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 01:42:27 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_index(t_node *node_a)
{
	int		count;
	t_node	*checker;
	t_node	*first_node_a;

	checker = node_a;
	first_node_a = node_a;
	while (node_a)
	{
		count = 0;
		while (checker)
		{
			if (node_a->value > checker->value)
				count++;
			checker = checker->next;
		}
		node_a -> index = count;
		node_a = node_a -> next;
		checker = first_node_a;
	}
	node_a = 0;
}

void	ft_make_list(int *av, t_deque *deque_a, t_node **node_a)
{
	int	i;

	i = 1;
	while (i <= av[0])
	{
		ft_lstadd_back(node_a, ft_lstnew(av[i]));
		i++;
	}
	deque_a->head = *node_a;
	deque_a->tail = ft_lstlast(*node_a);
	deque_a->size = ft_lstsize(*node_a);
}

void	ft_init_deq(int *av, t_deque *deque_a, t_node *node_a)
{
	ft_make_list(av, deque_a, &node_a);
	ft_make_index(node_a);
}
