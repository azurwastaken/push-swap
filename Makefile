# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 12:06:44 by mcaseaux          #+#    #+#              #
#    Updated: 2019/01/13 14:53:00 by mcaseaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CHCK		=	checker

CC			=	gcc # -fsanitize=address -g3
FLAGS		=	-Wall -Wextra -Werror

SRCS_PS		=	push-swap/main.c \
                	push-swap/ft_atol.c \
					push-swap/ft_putstr.c \
					push-swap/ft_strcmp.c \
					push-swap/ft_strlen.c \
					push-swap/ft_tabcpy.c \
					push-swap/instruct.c \
					push-swap/instruct2.c \
					push-swap/parse_util.c \
					push-swap/parse.c \
					push-swap/sort.c \
					push-swap/stack_to_top.c \
					push-swap/util.c \
					push-swap/util2.c

SRCS_CHCK	=	checkers/main.c \
                    checkers/checker.c \
                    checkers/ft_atol.c \
					checkers/ft_memset.c \
					checkers/ft_putstr.c \
					checkers/ft_strcmp.c \
					checkers/ft_strcpy.c \
					checkers/ft_strdel.c \
					checkers/ft_strlen.c \
					checkers/ft_strncat.c \
					checkers/ft_strnew.c \
					checkers/get_next_line.c \
					checkers/instruct.c \
					checkers/instruct2.c \
					checkers/parse.c \
					checkers/parse_util.c \
					checkers/ft_bzero.c

OBJDIR		=		bin/
OBJS_PS		=		$(addprefix $(OBJDIR), $(SRCS_PS:.c=.o))
OBJS_CHCK	=		$(addprefix $(OBJDIR), $(SRCS_CHCK:.c=.o))


all: $(OBJDIR) $(NAME) $(CHCK)

$(NAME): $(OBJS_PS)
	@echo "Creating the push_swap executable..."
	@$(CC) $(FLAGS) $(OBJS_PS) -o $(NAME)
	@echo "push_swap made!"

$(CHCK): $(OBJS_CHCK)
	@echo "Creating the ckecker executable..."
	@$(CC) $(FLAGS) $(OBJS_CHCK) -o $(CHCK)
	@echo "checker made!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)checkers $(OBJDIR)push-swap

$(OBJDIR)%.o: %.c
	@$(CC) $(FLAGS) -Ipush-swap -Ichecker -o $@ -c $<


clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -rf $(NAME)
	@/bin/rm -f $(CHCK)

re: fclean all

.PHONY: all clean fclean re
