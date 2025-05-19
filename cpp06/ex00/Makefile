# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrouves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 18:27:35 by mrouves           #+#    #+#              #
#    Updated: 2025/05/19 21:58:24 by mykle            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			:= ex00

SOURCES			:= main.cpp \
				ScalarConverter.cpp\

DIR_HEADERS		:= .
DIR_SOURCES		:= .
DIR_OBJS		:= .objs

OBJS			:= $(addprefix $(DIR_OBJS)/, $(SOURCES:%.cpp=%.o))

CC				:= c++
CPPFLAGS		:= -Wall -Wextra -Werror -std=c++98
LDFLAGS			:= -Wall -Wextra -Werror -std=c++98
LDLIBS			:= -I $(DIR_HEADERS)

DIR_DUP			= mkdir -p $(@D)
BOLD			= \033[1m
OK_COLOR		= \033[0;32m
NO_COLOR		= \033[m

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@printf "$(BOLD)$@$(NO_COLOR) compiled $(OK_COLOR)successfully$(NO_COLOR)\n"

$(DIR_OBJS)/%.o: $(DIR_SOURCES)/%.cpp
	@$(DIR_DUP)
	@$(CC) $(CPPLAGS) -c $< -o $@

clean:
	@rm -rf $(DIR_OBJS)
	@printf "Cleaned $(BOLD)$(DIR_OBJS)$(NO_COLOR)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "Cleaned $(BOLD)$(NAME)$(NO_COLOR)\n"

re: fclean all

.PHONY: clean fclean re all
