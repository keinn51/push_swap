/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 04:26:34 by kyungsle          #+#    #+#             */
/*   Updated: 2022/06/08 02:12:42 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

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

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_lstdel(t_list **head_ptr, t_list *curr_ptr);
int		ft_same_strcmp(char *s1, char *s2);
void	end_of_file(t_deque *deque_a, t_deque *deque_b);
size_t	ft_strlen(const char *str);
void	ft_check_arg(int ac, char **av);
void	ft_init_deq(int *av, t_deque *deque_a, t_node *node_a);
void	ft_alloc_deq(t_deque **deque_a, t_deque **deque_b);
t_deque	*ft_deqnew(t_deque *lst);
int		check_sorted(t_deque *deque_a);
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
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char **av);
int		count_split_size(char **av);
int		check_size(char **av, int i, int j);
int		alloc_result(char **result, int *index, int *j, int *prev_j);
void	make_result(char *word, char *av, int index, int length);
int		check_rest(char **av, int i, int j);
int		*ft_parse_arg(int ac, char **av);

#endif
