# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/29 16:41:59 by mkitano           #+#    #+#              #
#    Updated: 2026/03/29 16:42:01 by mkitano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98

SRC = contact.cpp phonebook.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all = $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "[\033[0;32mOK\033[0m] $(NAME) COMPILED!"

%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@
	@echo "[\033[0;32mOK\033[0m] $< COMPILED!"

clean:
	rm -f $(OBJ)
	@echo "[\033[0;32mOK\033[0m] FILES CLEAR!"

fclean: clean
	rm -f $(NAME)
	@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"

re: fclean all

.PHONY: all clean fclean re