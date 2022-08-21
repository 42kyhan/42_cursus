NAME	= megaphone
CXX 	= clang++
CXXFLAG	= -Wall -Werror -Wextra -std=c++98
RM		= rm -f

RED = \033[0;31m
GREEN = \033[0;32m
GREY = \033[2;37m
MAGENTA = \033[0;35m
NO_COLOR = \033[0m

SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(CXX) $(CXXFLAG) $(OBJ) -o $(NAME)
			@echo "$(GREY) $(NAME) compiled $(GREEN) ✔✔✔ $(NO_COLOR)"

run:		all
			./$(NAME) "shhhhh... I think the students are asleep..."
			./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
			./$(NAME)

clean:		
			@clear
			@$(RM) $(OBJ)
			@echo "$(RED) *** object file is deleted *** $(NO_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED) *** $(NAME) is deleted *** $(NO_COLOR)"

re:			fclean all

.PHONY:		all re clean fclean run

.SILENT:	$(OBJ)