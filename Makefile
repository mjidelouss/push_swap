# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 17:05:15 by aelousse          #+#    #+#              #
#    Updated: 2022/02/05 17:05:18 by aelousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
SRC = push_swap.c push_swap_utils.c push_swap_utils1.c push_swap_utils2.c push_swap_utils3.c swap_operations.c rotate_operations.c reverse_rotate_operations.c push_operations.c fill_stack.c sort_stack.c sort_stack_utils.c push_swap_utils4.c
BNS_SRC = checker.c push_swap_utils3.c push_swap_utils.c get_next_line.c fill_stack.c push_swap_utils1.c push_swap_utils2.c swap_operations.c rotate_operations.c reverse_rotate_operations.c push_operations.c push_swap_utils4.c
OBJS = ${SRC:.c=.o}
BOBJ = ${BNS_SRC:.c=.o}
CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)
	@echo "Compiling Successfull"

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(BOBJ)
	@$(CC) $(CFLAGS) $(BNS_SRC) -o $(BONUS_NAME)
	@echo "Compiling Successfull"

clean:
	@$(RM) $(OBJS) $(BOBJ)
	@echo "Object Files Removed Successfully"

fclean:clean
	@$(RM) all
	@echo "Clear"

re: fclean all
