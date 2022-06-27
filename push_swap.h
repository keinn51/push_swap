/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 01:39:13 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/07 16:13:13 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_deque
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}					t_deque;

int		*ft_parse_arg(int ac, char **av);
void	ft_alloc_deq(t_deque **deque_a, t_deque **deque_b);
void	ft_init_deq(int *av, t_deque *deque_a, t_node *node_a);
int		check_sorted(t_deque *deque_a);
void	sort_small_size(t_deque *deque_a, t_deque *deque_b, int size);
void	a_to_b(t_deque *deque_a, t_deque *deque_b);
void	b_to_a(t_deque *deque_a, t_deque *deque_b);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
t_deque	*ft_deqnew(t_deque *lst);
char	**ft_split(char **av);
int		count_split_size(char **av);
int		check_size(char **av, int i, int j);
int		alloc_result(char **result, int *index, int *j, int *prev_j);
void	make_result(char *word, char *av, int index, int length);
int		check_rest(char **av, int i, int j);
void	ft_check_arg(int ac, char **av);
t_node	*ft_lstnew(int value);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
int		ft_lstsize(t_node *lst);
void	ft_renew_lstsize(t_deque *deque_a, t_deque *deque_b);
void	ft_swap_a(t_deque *deque_a);
void	ft_swap_b(t_deque *deque_b);
void	ft_swap_ab(t_deque *deque_a, t_deque *deque_b);
void	ft_push_a(t_deque *deque_a, t_deque *deque_b);
void	ft_push_b(t_deque *deque_a, t_deque *deque_b);
void	ft_rotate_a(t_deque *deque_a);
void	ft_rotate_b(t_deque *deque_b);
void	ft_rotate_ab(t_deque *deque_a, t_deque *deque_b);
void	ft_reverse_rotate_a(t_deque *deque_a);
void	ft_reverse_rotate_b(t_deque *deque_b);
void	ft_reverse_rotate_ab(t_deque *deque_a, t_deque *deque_b);

#endif
