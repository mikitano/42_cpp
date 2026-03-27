NAME = megaphone

CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98

SRC = megaphone.cpp
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