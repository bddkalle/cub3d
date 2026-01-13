# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 11:47:25 by fschnorr          #+#    #+#              #
#    Updated: 2026/01/09 15:35:11 by fschnorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

INCLUDE = -I include $(LIBFT_INCLUDES) $(MLX_INCLUDE) $(LAPI_INCLUDE)
SRC =	$(addsuffix .c,							\
		$(addprefix src/, 						\
							draw				\
							error				\
							free				\
							hook				\
							init				\
							init2				\
							init3				\
							main				\
							player				\
		))										\
		$(addsuffix .c,							\
		$(addprefix src/map/,					\
							parse_map			\
		))										\
		$(addsuffix .c,							\
		$(addprefix src/validate/,				\
							validate			\
		))
OBJS := $(SRC:.c=.o)

LIBFT_INCLUDES = -I $(LIBFT_DIR)/includes
LIBFT_DIR = lib/libft
LIBFT_AR = $(LIBFT_DIR)/libft.a

MLX_INCLUDE = -I $(MLX_DIR)
MLX_DIR = lib/minilibx-linux
MLX_LINK = -L$(MLX_DIR) -lmlx_Linux

LAPI_INCLUDE = -I $(LAPI_DIR)/include
LAPI_DIR = /usr
LAPI_LINK = -L$(LAPI_DIR)/lib -lXext -lX11 -lm -lz

CC = cc
CFLAGS = -Wall -Wextra -Werror
MFLAGS = --no-print-directory
VFLAGS = -g -O0

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR) $(MFLAGS)
	@echo -n "run cc for $(NAME)..."
	@$(CC) $^ $(LIBFT_AR) $(MLX_LINK) $(LAPI_LINK) -o $(NAME) $(CFLAGS) $(INCLUDE) 
	@echo "done"

%.o: %.c
	@$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDE)

clean:
	@rm -f $(OBJS)

fclean: clean
	@echo -n "run fclean for $(NAME)..."
	@rm -f $(NAME)
	@echo "done"
	@make fclean -C $(LIBFT_DIR) $(MFLAGS)

re: fclean all

debug: CFLAGS += -g -O0
debug: $(NAME)
	@gdb $(NAME)

run: all
	@./$(NAME) $(ARG) || true

valgrind: CFLAGS += -g -O0
valgrind: re
#	@make -C $(FT_PRINTF_DIR) $(MFLAGS)
#	@make -C $(GNL_DIR) $(MFLAGS)
#	$(CC) $^ $(FT_PRINTF_AR) $(GNL_AR) -o $(NAME) $(CFLAGS) $(VFLAGS) $(INCLUDE) $(MLX_LINK) $(LAPI_LINK)
	@valgrind --suppressions=valgrind.supp --quiet --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes -s ./$(NAME) $(ARG)

checkup:
	@echo "Checking for memory leaks..."
	@make valgrind || true
	@make norm

norm:
	@echo "Checking for memory leaks..."
	@norminette include src $(FT_PRINTF_DIR) $(GNL_DIR)

setup:
	@echo "Installing MiniLibX dependencies..."
	@sudo apt-get update && sudo apt-get install -y xorg libxext-dev zlib1g-dev libbsd-dev
	@echo "Configuring MiniLibX..."
	@cd $(MLX_DIR) && ./configure
	@echo "MiniLibX setup complete."

42_setup:
	@echo "Configuring MiniLibX..."
	@cd $(MLX_DIR) && ./configure
	@echo "MiniLibX setup complete."
	

.PHONY: all setup clean fclean re debug run valgrind checkup norm setup 42_setup
