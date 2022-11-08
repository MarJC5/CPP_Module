# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmartin <jmartin@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 09:19:33 by jmartin           #+#    #+#              #
#    Updated: 2022/11/08 15:24:34 by jmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN	= \033[0;32m
RED 	= \033[0;31m
ORANGE	= \033[0;33m
CYAN	= \033[0;36m
RESET	= \033[0m

# PROGRAM
NAME		= zombie

# FOLDERS & FILES
SRCS_DIR	= ./
SRCS_FILES	= main.cpp
SRCS_FILES	+= 
SRCS		:= ${patsubst %, ${SRCS_DIR}%, ${SRCS_FILES}}

O_DIR		= ./objs/
OBJS_FILES	:= ${SRCS_FILES:.cpp=.o}
OBJS		:= ${patsubst %, ${O_DIR}%, ${OBJS_FILES}}

# FLAGS
CC			= g++
CFLAGS		= -Wall -Wextra -Werror
CPP_FLAGS 	= -std=c++98 -pedantic

# COMMANDS
MKDIR		= mkdir -p
RM			= rm -rf

all: ${NAME}

# Compile normal executable
${NAME}: ${O_DIR} ${OBJS}
	@${CC} ${CFLAGS} ${CPP_FLAGS} -o ${NAME} ${OBJS}
	@echo "[$(ORANGE)$(NAME)$(RESET)] Creation *.o files & compilation : $(GREEN)OK$(RESET)"
	@echo "[\033[1;32msuccess$(RESET)]: $(NAME) is ready"

# Create objects directory
${O_DIR}:
	@${MKDIR} ${O_DIR}

# Compile normals objects
${O_DIR}%.o: ${SRCS_DIR}%.cpp
	@${CC} ${CFLAGS} ${HEADS} -o $@ -c $<

clean:
	@${RM} -r ${O_DIR}
	@echo "[$(ORANGE)$(NAME)$(RESET)] clean *.o files : $(GREEN)OK$(RESET)"

fclean:	clean
	@${RM} ${NAME}
	@echo "[$(ORANGE)$(NAME)$(RESET)] fclean: $(GREEN)OK$(RESET)"
	@echo "[\033[1;32msuccess$(RESET)]: $(NAME) has been clean up"

re: fclean all

.PHONY: all clean fclean re