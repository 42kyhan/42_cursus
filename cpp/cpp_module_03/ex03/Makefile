NAME		= ex02
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wshadow -Wno-shadow -std=c++98 -pedantic
RM			= rm -rf

SRCS		= main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp
OBJS		= $(SRCS:.cpp=.o)

all	:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean