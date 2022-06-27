/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:46:18 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 15:08:43 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_same_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0' )
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_empty(t_deque *deque)
{
	if (!deque -> head && !deque -> tail && !deque -> size)
		return (1);
	return (0);
}

void	end_of_file(t_deque *deque_a, t_deque *deque_b)
{
	if (check_sorted(deque_a) && check_empty(deque_b))
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
	ft_putstr_fd("KO\n", 1);
	exit(0);
}
