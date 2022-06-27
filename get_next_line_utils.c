/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 12:24:55 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/08 03:12:36 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (!c)
		return (((char *)str + i));
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		exit (1);
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	char	*temp;

	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		exit (1);
	result = temp;
	while (*s1)
		*(temp++) = *(s1++);
	while (*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	return (result);
}

char	*ft_lstdel(t_list **head_ptr, t_list *curr_ptr)
{
	t_list	*temp;

	if (*head_ptr == curr_ptr)
	{
		*head_ptr = curr_ptr->next;
		free(curr_ptr->content);
		curr_ptr->content = NULL;
		free(curr_ptr);
		curr_ptr = NULL;
	}
	else
	{
		temp = *head_ptr;
		while (temp->next != curr_ptr)
			temp = temp->next;
		temp->next = curr_ptr->next;
		free(curr_ptr->content);
		curr_ptr->content = NULL;
		free(curr_ptr);
		curr_ptr = NULL;
	}
	return (NULL);
}
