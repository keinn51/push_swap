/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:26:43 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 16:03:44 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	execute_command(t_deque *deque_a, t_deque *deque_b, char *line)
{
	if (ft_same_strcmp("sa\n", line))
		ft_swap_a(deque_a);
	else if (ft_same_strcmp("sb\n", line))
		ft_swap_b(deque_b);
	else if (ft_same_strcmp("ss\n", line))
		ft_swap_ab(deque_a, deque_b);
	else if (ft_same_strcmp("pa\n", line))
		ft_push_a(deque_a, deque_b);
	else if (ft_same_strcmp("pb\n", line))
		ft_push_b(deque_a, deque_b);
	else if (ft_same_strcmp("ra\n", line))
		ft_rotate_a(deque_a);
	else if (ft_same_strcmp("rb\n", line))
		ft_rotate_b(deque_b);
	else if (ft_same_strcmp("rr\n", line))
		ft_rotate_ab(deque_a, deque_b);
	else if (ft_same_strcmp("rra\n", line))
		ft_reverse_rotate_a(deque_a);
	else if (ft_same_strcmp("rrb\n", line))
		ft_reverse_rotate_b(deque_b);
	else if (ft_same_strcmp("rrr\n", line))
		ft_reverse_rotate_ab(deque_a, deque_b);
	else
		return (1);
	return (0);
}

void	check_stdin(t_deque *deque_a, t_deque *deque_b)
{
	char	*line;

	line = get_next_line(0);
	if (line == NULL)
		end_of_file(deque_a, deque_b);
	else
	{
		if (execute_command(deque_a, deque_b, line))
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(line);
		line = NULL;
	}
}

int	main(int ac, char **av)
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	t_node	*node_a;
	int		*parsing;

	if (ac == 1)
		return (0);
	deque_a = NULL;
	deque_b = NULL;
	node_a = NULL;
	parsing = ft_parse_arg(ac, av);
	ft_alloc_deq(&deque_a, &deque_b);
	ft_init_deq(parsing, deque_a, node_a);
	while (1)
		check_stdin(deque_a, deque_b);
	return (0);
}
