/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:38:57 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 15:49:26 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_deque *deque_a, t_deque *deque_b)
{
	int	size;

	size = deque_a -> size;
	if (check_sorted(deque_a))
		return ;
	else if (size <= 3 || size == 5)
		sort_small_size(deque_a, deque_b, size);
	else
	{
		a_to_b(deque_a, deque_b);
		b_to_a(deque_a, deque_b);
	}
}

int	main(int ac, char **av)
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	t_node	*node_a;
	int		*parsed_arr;

	deque_a = NULL;
	deque_b = NULL;
	node_a = NULL;
	parsed_arr = ft_parse_arg(ac, av);
	ft_alloc_deq(&deque_a, &deque_b);
	ft_init_deq(parsed_arr, deque_a, node_a);
	push_swap(deque_a, deque_b);
	return (0);
}
