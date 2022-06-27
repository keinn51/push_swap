/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:42:17 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/08 03:06:02 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new_lst;

	new_lst = (t_node *)malloc(sizeof(t_node));
	if (new_lst == NULL)
		exit (1);
	new_lst->value = value;
	new_lst -> index = 0;
	new_lst -> next = NULL;
	new_lst -> prev = NULL;
	return (new_lst);
}

t_node	*ft_lstlast(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while ((lst->next) != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*curr;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr -> next)
	{
		curr -> next -> prev = curr;
		curr = curr -> next;
	}
	curr -> next = new;
	new -> prev = curr;
	new -> next = NULL;
}

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_renew_lstsize(t_deque *deque_a, t_deque *deque_b)
{
	deque_a->size = ft_lstsize(deque_a->head);
	deque_b->size = ft_lstsize(deque_b->head);
}
