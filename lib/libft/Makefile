# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschnorr <fschnorr@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 13:30:00 by fschnorr          #+#    #+#              #
#    Updated: 2025/11/07 13:58:34 by fschnorr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =	$(addsuffix .c,								\
		$(addprefix src/ctype/, 					\
		                		ft_isalnum   		\
                            	ft_isalpha   		\
								ft_isascii   		\
								ft_isdigit   		\
								ft_isprint   		\
								ft_isspace  		\
								ft_tolower   		\
								ft_toupper   		\
        ))											\
		$(addsuffix .c,								\
		$(addprefix src/get_next_line/, 			\
								get_next_line		\
		))											\
    	$(addsuffix .c,							\
		$(addprefix src/memory/, 				\
								ft_bzero    	\
							 	ft_memchr   	\
							 	ft_memcmp   	\
								ft_memcpy   	\
							 	ft_memmove  	\
							 	ft_memset   	\
		))										\
		$(addsuffix .c,							\
		$(addprefix src/stdio/, 				\
								ft_printf		\
								ft_putchar_fd	\
								ft_putendl_fd	\
								ft_putnbr_fd	\
								ft_putptr_fd	\
								ft_putstr_fd	\
		))										\
		$(addsuffix .c,							\
		$(addprefix src/stdlib/, 				\
								ft_atoi			\
								ft_atol			\
								ft_calloc		\
								ft_intlen		\
								ft_itoa			\
		))										\
		$(addsuffix .c,							\
		$(addprefix src/string/, 				\
								ft_split		\
								ft_str_isin_strs\
								ft_strchr		\
								ft_strcmp		\
								ft_strdup		\
								ft_striteri		\
								ft_strjoin		\
								ft_strlcat		\
								ft_strlcpy		\
								ft_strlen		\
								ft_strmapi		\
								ft_strncmp		\
								ft_strnstr		\
								ft_strrchr		\
								ft_strtrim		\
								ft_substr		\
											))	\
		$(addsuffix .c, 						\
		$(addprefix src/utils/, 				\
								ft_c_isin_str	\
								ft_linelen		\
		))
OBJS_DIR = obj
OBJS := $(addprefix $(OBJS_DIR)/, $(notdir $(SRC:.c=.o)))

vpath %.c src/ctype src/get_next_line src/memory src/stdio src/stdlib src/string src/utils

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "run ar for libft..."
	@ar rcs $(NAME) $(OBJS)
	@echo "done"
	
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@cc -Wextra -Wall -Werror -Iincludes -c $< -o $@
	
clean:
	@rm -rf $(OBJS_DIR)
	
fclean: clean
	@echo -n "run fclean for libft..."
	@rm -f $(NAME)
	@echo "done"

re: fclean all
