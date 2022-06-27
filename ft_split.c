/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:40:50 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/08 03:09:13 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_result_from_av(char **result, char **av)
{
	int		i;
	int		j;
	int		prev_j;
	int		index;

	i = 1;
	index = 0;
	while (av[i] != NULL)
	{
		j = 0;
		while (av[i][j] != 0)
		{
			prev_j = j;
			j = check_size(av, i, j);
			if (alloc_result(result, &index, &j, &prev_j))
				break ;
			make_result(result[index], av[i], prev_j, j - prev_j);
			if (av[i][j] == 0 || check_rest(av, i, j))
				break ;
			index++;
		}
		index++;
		i++;
	}
}

char	**ft_split(char **av)
{
	int		split_size;
	char	**result;

	result = NULL;
	split_size = count_split_size(av);
	result = (char **)malloc(sizeof(char *) * split_size + 1);
	if (result == NULL)
		exit (1);
	result[split_size + 1] = NULL;
	make_result_from_av(result, av);
	return (result);
}
