# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/05 13:50:43 by ipersids          #+#    #+#              #
#    Updated: 2025/01/09 15:48:01 by ipersids         ###   ########.fr        #
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
CFLAGS			:= -Wall -Wextra -Werror -g
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
				   src/circular-buffer/queue_remove_last.c \
				   \
				   src/destructor/ps_destroy_data_exit.c \
				   src/destructor/ps_free_array.c \
				   \
				   src/initialisation/ps_data_init.c \
				   src/initialisation/ps_get_numbers.c \
				   src/initialisation/ps_rank_ascending.c \
				   src/initialisation/ps_sorted_ascending.c \
				   src/initialisation/ps_stacks_init.c \
				   \
				   src/commands/ps_push.c \
				   src/commands/ps_reverse_rotate.c \
				   src/commands/ps_rotate.c \
				   src/commands/ps_swap.c \
				   src/commands/ps_save_command.c \
				   src/commands/ps_print_commands.c \
				   \
				   src/push-swap/ps_move_from_to.c \
				   src/push-swap/ps_sort_helpers.c \
				   src/push-swap/ps_sort_one.c \
				   src/push-swap/ps_sort_three.c \
				   src/push-swap/ps_sort_two.c \
				   src/push-swap/ps_sort.c \
				   src/push-swap/ps_value_helpers.c \
				   src/push-swap/ps_choose_sort.c \
				   \

SRC_MAIN		:= src/main.c
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
	$(CC) $(CFLAGS) $(TEST_OBJS) $(OBJS) $(HDRS) $(LIBS) -o $(TEST_NAME)

tclean: clean
	$(RM) -f $(TEST_NAME) $(TEST_OBJS)

.PHONY: all clean fclean re update-submodule build-submodule
