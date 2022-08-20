CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	get_time_bonus.c \
		init_bonus.c \
		libft_bonus.c \
		parse_bonus.c \
		philo_action_bonus.c \
		philosophers_bonus.c \
		routine_bonus.c

OBJS = $(SRCS:%.c=%.o)

NAME = philo_bonus

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