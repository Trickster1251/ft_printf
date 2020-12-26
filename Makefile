# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walethea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/26 20:30:07 by walethea          #+#    #+#              #
#    Updated: 2020/12/26 20:31:06 by walethea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INC = ft_printf.h
LIBA = ./libft/libft.a
SRCS =	ft_is_flag.c \
		ft_printf.c \
		ft_parcer.c \
		ft_processor.c \
		ft_uputnbr.c \
		ft_print_u.c \
		ft_print_int.c \
		ft_print_x.c \
		ft_print_p.c \
		ft_print_c.c \
		ft_print_s.c \
			
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
