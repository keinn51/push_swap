# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 01:40:24 by kyungsle          #+#    #+#              #
#    Updated: 2022/06/07 16:13:32 by kyungsle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= gcc
RM= rm -f
CFLAGS= -Wall -Wextra -Werror
NAME= push_swap
CHECKER= checker
SRCS= push_swap.c \
	 ft_sort_small_size.c \
	 ft_a_to_b.c \
	 ft_b_to_a.c \
	 ft_check_arg.c \
	 ft_init_deq.c \
	 ft_deque_util.c \
	 ft_list_util.c \
	 ft_util.c \
	 ft_split.c \
	 ft_split_util.c \
	 ft_parse_arg.c \
	 ft_push.c \
	 ft_swap.c \
	 ft_rotate.c \
	 ft_reverse_rotate.c
SRCSB= push_swap_bonus.c \
	 push_swap_bonus_util.c \
	 ft_push_bonus.c \
	 ft_reverse_rotate_bonus.c \
	 ft_rotate_bonus.c \
	 ft_swap_bonus.c \
	 get_next_line_utils.c \
	 get_next_line.c \
	 ft_check_arg.c \
	 ft_init_deq.c \
	 ft_deque_util.c \
	 ft_list_util.c \
	 ft_util.c \
	 ft_split.c \
	 ft_split_util.c \
	 ft_parse_arg.c
OBJS=$(SRCS:.c=.o)
OBJSB= $(SRCSB:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(CHECKER)

all : $(NAME)

bonus : $(CHECKER)

clean :
	$(RM) $(OBJS) $(OBJSB)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(CHECKER)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
