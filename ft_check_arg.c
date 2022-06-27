/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:38 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 13:51:34 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_spaces(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
			{
				if (av[i][j + 1] == 0)
					return (1);
				j++;
			}
			else
				break ;
		}
		i++;
	}
	return (0);
}

int	check_null(char **av)
{
	int	i;
	int	length;

	i = 1;
	while (av[i] != 0)
	{
		length = ft_strlen(av[i]);
		if (length == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_not_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32
					|| av[i][j] == '+' || av[i][j] == '-')
				j++;
			else if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	check_sign(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if (av[i][j] == '+' || av[i][j] == '-')
			{
				j++;
				if (av[i][j] == 0 || av[i][j] == '+' || av[i][j] == '-'
						|| (av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
					return (1);
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}

void	ft_check_arg(int ac, char **av)
{
	if (ac <= 1)
		exit (0);
	if (check_null(av) || check_spaces(av)
		|| check_not_digit(av) || check_sign(av))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	return ;
}
