/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:41:21 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/08 03:15:20 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_split_size(char **av)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	length = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			if ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
				j++;
			else
			{
				while (av[i][j] != 0
					&& (av[i][j] < 9 || av[i][j] > 13) && av[i][j] != 32)
					j++;
				length++;
			}
		}
		i++;
	}
	return (length);
}

int	check_size(char **av, int i, int j)
{
	while ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
	{
		j++;
		if (av[i][j] == 0)
			return (0);
	}
	while (('0' <= av[i][j] && '9' >= av[i][j])
	|| '+' == av[i][j] || '-' == av[i][j])
		j++;
	return (j);
}

int	alloc_result(char **result, int *index, int *j, int *prev_j)
{
	if (*j != 0)
	{
		result[*index] = (char *)malloc(sizeof(char) * (*j - *prev_j + 1));
		if (result[*index] == NULL)
			exit(1);
		return (0);
	}
	return (1);
}

void	make_result(char *word, char *av, int index, int length)
{
	int		i;

	i = 0;
	while (i < length)
	{
		word[i] = av[index];
		index++;
		i++;
	}
	word[i] = '\0';
}

int	check_rest(char **av, int i, int j)
{
	while (av[i][j] != 0)
	{
		if ((av[i][j] >= 9 && av[i][j] <= 13) || av[i][j] == 32)
		{
			if (av[i][j + 1] == 0)
				return (1);
			j++;
		}
		else
			return (0);
	}
	return (1);
}
