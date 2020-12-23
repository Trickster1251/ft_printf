NAME = libftprintf.a
INC = ft_printf.h
LIBA = ./libft/libft.a
SRCS =	ft_is_flag.c \
		ft_printf.c \
		ft_parcer.c \
		ft_processor.c \
			
OBJS = $(SRCS:.c=.o)
FLAG = -Wall -Wextra -Werror
.c.o:
	@gcc $(FLAG) -c $< -o $@
$(NAME): $(OBJS)
	@make -C ./libft
	@cp $(LIBA) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libftprint.a has been created"
all: $(NAME)
clean:
	@make clean -C ./libft
	@rm -rf $(OBJS)
	@echo "Binaries have been removed"
fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME) a.out
	@echo "Libftprint.a and binaries has been removed"
re: fclean all
.PHONY: all clean fclean re