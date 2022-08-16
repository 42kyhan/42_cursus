CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	creat_thread.c \
		get_time.c \
		init.c \
		libft.c \
		parse.c \
		philo_action.c \
		philosophers.c \
		routine.c

OBJS = $(SRCS:%.c=%.o)

NAME = philo

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -lpthread $(OBJS) -o $(NAME)

%.o		:		%.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re