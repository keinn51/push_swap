/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:47 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 17:03:23 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b_util(t_deque *deque_a, t_deque *deque_b, int *iter, float scale)
{
	int	top;

	top = deque_a -> head -> index;
	if (top <= *iter)
	{
		ft_push_b(deque_a, deque_b);
		(*iter)++;
	}
	else if (*iter < top && top <= *iter + scale)
	{
		ft_push_b(deque_a, deque_b);
		ft_rotate_b(deque_b);
		(*iter)++;
	}
	else if (*iter + scale < top)
		ft_rotate_a(deque_a);
}

void	a_to_b(t_deque *deque_a, t_deque *deque_b)
{
	int		size;
	int		iter;
	float	scale;

	size = deque_a -> size;
	iter = 0;
	scale = 0.000000053 * size * size + 0.03 * size + 14.5;
	while (iter < size)
		a_to_b_util(deque_a, deque_b, &iter, scale);
}
