/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:10 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 12:14:43 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parameter_compare(int *result)
{
	int	i;
	int	j;
	int	index;

	i = 1;
	index = 0;
	while (index < result[0])
	{
		j = i + 1;
		while (result[j] != 0)
		{
			if (result[i] == result[j])
			{
				ft_putstr_fd("Error\n", 2);
				exit (1);
			}
			j++;
		}
		i++;
		index++;
	}
}

void	make_int_array(int *result, char **temp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		result[i + 1] = ft_atoi(temp[i]);
		free(temp[i]);
		temp[i] = NULL;
		i++;
	}
	result[i + 1] = 0;
	free(temp);
	temp = NULL;
}

int	*ft_parse_arg(int ac, char **av)
{
	int		split_size;
	int		*result;
	char	**temp;

	ft_check_arg(ac, av);
	temp = ft_split(av);
	split_size = 0;
	while (temp[split_size])
		split_size++;
	result = (int *)malloc(sizeof(int) * (split_size + 2));
	if (result == NULL)
		exit(1);
	result[0] = split_size;
	make_int_array(result, temp, split_size);
	parameter_compare(result);
	return (result);
}
