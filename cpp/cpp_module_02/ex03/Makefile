NAME = ex03
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic
RM = rm -f

SRCS = Fixed.cpp main.cpp bsp.cpp Point.cpp
OBJS = ${SRCS:.cpp=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean