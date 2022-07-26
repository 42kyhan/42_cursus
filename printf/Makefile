NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a

SRCS			= 	ft_printf.c \
					ft_printf_utils.c \
					print_diu.c \
					print_diu_utils.c \
					print_perc.c \
					print_px.c \
					print_px_utils.c \
					print_s.c

SRCS_BONUS		=	ft_printf_bonus.c \
					ft_printf_utils_bonus.c \
					print_diu_bonus.c \
					print_diu_utils_bonus.c \
					print_perc_bonus.c \
					print_px_bonus.c \
					print_px_utils_bonus.c \
					print_s_bonus.c

OBJS			=	$(SRCS:%.c=%.o)

OBJS_BONUS		=	$(SRCS_BONUS:%.c=%.o)

LIBC			=	ar rc

FLAGS			=	-Wall -Wextra -Werror

ifdef WITH_BONUS
		OBJS_FILES = $(OBJS) $(OBJS_BONUS)
else
		OBJS_FILES = $(OBJS)
endif

all		:	$(NAME)

$(NAME)	:	$(OBJS_FILES)
			make all -C $(LIBFT)/
			cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
			$(LIBC) $(NAME) $(OBJS_FILES)

%.o		:	%.c
			gcc $(FLAGS) -c $^ -I./ -o $@

bonus	:
			make WITH_BONUS=1 all

clean	:
			rm -f $(OBJS) $(OBJS_BONUS)
			make clean -C $(LIBFT)

fclean	:	clean
			rm -f $(NAME)
			rm -f $(LIBFT_LIB)
			make fclean -C $(LIBFT)

re		:	fclean all

.PHONY	:	all clean fclean re bonus
