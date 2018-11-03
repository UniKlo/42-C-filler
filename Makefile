#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/10 18:38:04 by khou              #+#    #+#              #
#    Updated: 2018/11/03 14:57:51 by khou             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

C = clang

NAME = filler

FLAGS = -Wall -Wextra -Werror -fsanitize=address

DIR_H = incl/

DIR_S = srcs/

HEADER = filler.h

SOURCES = test.c

SRCS = $(addprefix $(DIR_S), $(SOURCES))

INCL = $(addprefix $(DIR_H), $(HEADER))

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft/
	@$(C) $(FLAGS) -L libft/ -lft $(SRCS) -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@echo "cleaned up objects"

fclean: clean
	@rm -f $(NAME)
	@rm -f *~
	@rm -f \#*\#
	@rm -f incl/*~
	@rm -f srcs/*~
	@rm -f srcs/\#*\#
	@rm -f a.out
	@rm -rf *dSYM
	@echo "reset"

re: fclean all

.PHONY: fclean re norme all clean
