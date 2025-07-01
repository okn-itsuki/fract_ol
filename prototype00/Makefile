# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iokuno <iokuno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/01 12:43:07 by iokuno            #+#    #+#              #
#    Updated: 2025/07/01 13:01:34 by iokuno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I inc -I minilibx-linux -I ft_printf -I libft
LFLAGS  = -L minilibx-linux -lmlx -lXext -lX11 -lm \
          -L ft_printf -lftprintf \
          -L libft -lft

RM      = rm -f

SRCDIR  = src
SRCFILE = main.c mandelbrot.c
SRCS    = $(addprefix $(SRCDIR)/, $(SRCFILE))
OBJS    = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_REPO = https://github.com/42Paris/minilibx-linux.git

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

$(MLX_LIB):
	@test -d $(MLX_DIR) || git clone $(MLX_REPO)
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean || true

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
