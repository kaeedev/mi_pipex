# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/10 10:58:45 by marvin            #+#    #+#              #
#    Updated: 2025/08/10 10:58:45 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CC := cc
CFLAGS	:= -Wextra -Wall -Werror -g

# --- Rutas de Librerías ---
LIBFT_DIR	:= ./includes/mi_libft
LIBFT_LIB	:= $(LIBFT_DIR)/libft.a

PRINTF_DIR	:= ./includes/ft_printf
PRINTF_LIB	:= $(PRINTF_DIR)/libftprintf.a

GNL_DIR		:= ./includes/mi_get_next_line

# --- Archivos del Proyecto ---
SRCS	:= $(shell find ./srcs -iname "*.c")
GNL_SRCS := $(shell find $(GNL_DIR) -iname "*.c")
OBJS	:= ${SRCS:.c=.o}
GNL_OBJS := ${GNL_SRCS:.c=.o}

# --- Includes y Enlazado de Librerías ---
HEADERS	:= -I ./includes -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(GNL_DIR)
LIBS	:= $(LIBFT_LIB) $(PRINTF_LIB)

# --- Colores para la Salida ---
GREEN = \033[0;32m
BLUE = \033[0;34m
NC = \033[0m

# --- Reglas Principales ---
all: $(NAME)

# El ejecutable depende de los objetos y librerías
$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT_LIB) $(PRINTF_LIB)
	@echo "$(BLUE)Enlazando $@...$(NC)"
	@$(CC) $(OBJS) $(GNL_OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✅ pipex compilado con éxito!$(NC)"

# Reglas para compilar cada librería por separado
$(LIBFT_LIB):
	@echo "$(BLUE)Compilando Libft...$(NC)"
	@$(MAKE) -sC $(LIBFT_DIR)

$(PRINTF_LIB):
	@echo "$(BLUE)Compilando ft_printf...$(NC)"
	@$(MAKE) -sC $(PRINTF_DIR)

# Regla para compilar archivos .c a .o
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compilando: $(notdir $<)\r"

# --- Reglas de Limpieza ---
clean:
	@rm -rf $(OBJS) $(GNL_OBJS)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(PRINTF_DIR) clean
	@echo "Limpiando archivos objeto."

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(PRINTF_DIR) fclean
	@echo "Limpiando todo."

re: fclean all

.PHONY: all clean fclean re