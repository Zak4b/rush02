# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 22:29:44 by asene             #+#    #+#              #
#    Updated: 2025/01/18 15:53:48 by asene            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02

INC = -I.
LIB = -L./libft/ -lft
FLAGS = -Wall -Wextra -Werror -g

SOURCES = \
	main.c \
	dict.c \
	dict_parser.c \
	sort_dict.c \
	dict_print.c \
	putnbr_char.c \
	utils.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))

$(NAME): $(OBJS)
	@make -s -C libft/
	cc $(FLAGS) -o $(NAME) $(OBJS) $(INC) $(LIB)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	cc $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

all: $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	
re: fclean all