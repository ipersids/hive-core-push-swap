# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 13:50:43 by ipersids          #+#    #+#              #
#    Updated: 2025/01/06 21:16:39 by ipersids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Platform-specific settings
ifeq ($(OS),Windows_NT)
    RM = del /q
    RM_DIR = rmdir /s /q
    LIB_EXT = .lib
else
    RM = rm -f
    RM_DIR = rm -rf
    LIB_EXT = .a
endif

# Program name
NAME			:= push_swap

# Submodule libft
SUBM_LIBFT_DIR	:= libft
SUBM_LIBFT_LIB	:= $(SUBM_LIBFT_DIR)/libft$(LIB_EXT)

# Compilation variables
CC				:= clang
CFLAGS			:= -Wall -Wextra -Werror
HDRS			:= -I. -I$(SUBM_LIBFT_DIR)/include -Iinclude
LIBS			:= -L$(SUBM_LIBFT_DIR) -lft

# Sources and objects
SRCS			:= src/circular-buffer/queue_add_vip.c \
				   src/circular-buffer/queue_dequeue.c \
				   src/circular-buffer/queue_empty.c \
				   src/circular-buffer/queue_enqueue.c \
				   src/circular-buffer/queue_free.c \
				   src/circular-buffer/queue_full.c \
				   src/circular-buffer/queue_init.c \
				   \
				   src/data/input_check.c \
				   \
				   src/service-utils/error_exit.c \
				   src/service-utils/memory_free.c \

SRC_MAIN		:= main.c
OBJS			:= $(SRCS:%.c=%.o)
OBJ_MAIN		:= $(SRC_MAIN:%.c=%.o)

# RULES
all: update-submodule build-submodule $(NAME)

$(NAME): $(OBJS) $(OBJ_MAIN)
	$(CC) $(CFLAGS) $(OBJS) $(OBJ_MAIN) $(HDRS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

clean:
	$(RM) -f $(OBJS) $(OBJ_MAIN)
	$(MAKE) -C $(SUBM_LIBFT_DIR) clean

fclean: clean
	$(RM) -rf $(NAME)
	$(MAKE) -C $(SUBM_LIBFT_DIR) fclean

re: fclean all

# Rule: update submodule Libft
update-submodule:
	git submodule update --init --recursive

# Rule: build Submodule Libft
build-submodule:
	$(MAKE) -C $(SUBM_LIBFT_DIR) 

# TESTING
TEST_NAME		:= test_main
TEST_SRCS		:= test_main.c
TEST_OBJS		:= $(TEST_SRCS:%.c=%.o)

test: update-submodule build-submodule $(TEST_NAME)

$(TEST_NAME): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -g $(TEST_OBJS) $(OBJS) $(HDRS) $(LIBS) -o $(TEST_NAME)

tclean: clean
	$(RM) -f $(TEST_NAME) $(TEST_OBJS)

.PHONY: all clean fclean re update-submodule build-submodule
