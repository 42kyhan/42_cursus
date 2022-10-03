NAME	= harlFilter
CXX		= clang++
CXXFLAG	= -Wall -Werror -Wextra -std=c++98
RM		= rm -f

RED = \033[0;31m
GREEN = \033[0;32m
GREY = \033[2;37m
MAGENTA = \033[0;35m
NO_COLOR = \033[0m

SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CXX) $(CXXFLAG) $(OBJS) -o $(NAME)
			@echo "$(GREY) $(NAME) compiled $(GREEN) ✔✔✔ $(NO_COLOR)"

clean:
			@clear
			@$(RM) $(OBJS)
			@echo "$(RED) *** object file is deleted *** $(NO_COLOR)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED) *** $(NAME) is deleted *** $(NO_COLOR)"

re:			fclean all

.PHONY:		all re clean fclean

.SILENT:	$(OBJS)