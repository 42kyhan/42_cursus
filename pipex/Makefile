CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS =	srcs/execve.c \
		srcs/get_heredoc.c \
		srcs/get_path.c \
		srcs/gnl_ut.c \
		srcs/gnl.c \
		srcs/init.c \
		srcs/libft1.c \
		srcs/libft2.c \
		srcs/open.c \
		srcs/parse.c \
		srcs/pipex.c \
		srcs/split.c \

SRCS_BONUS = bonus/execve_bonus.c \
			bonus/get_heredoc_bonus.c \
			bonus/get_path_bonus.c \
			bonus/gnl_ut_bonus.c \
			bonus/gnl_bonus.c \
			bonus/init_bonus.c \
			bonus/libft1_bonus.c \
			bonus/libft2_bonus.c \
			bonus/open_bonus.c \
			bonus/parse_bonus.c \
			bonus/pipex_bonus.c \
			bonus/split_bonus.c \

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = pipex

BONUS = pipex_bonus

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

$(BONUS) : $(OBJS_BONUS)
	$(CC) -o $(BONUS) $(OBJS)

%.o		:		%.c
		gcc $(CFLAGS) -c $^ -I./ -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	$(RM) $(OBJS) $(NAME) $(BONUS) $(OBJS_BONUS) $(BONUS)

re :
	make fclean
	make all

.PHONY : all clean fclean bonus re