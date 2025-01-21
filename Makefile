NAME        := so_long
BONUS_NAME  := so_long_bonus
CC          := cc
CFLAGS      := -g -Wextra -Wall -Werror -Wunreachable-code -Ofast

GIT_MLX = git clone https://github.com/42-Fundacion-Telefonica/MLX42.git $(LIBMLX)
LIBMLX      := ./include/MLX42

LIBS        := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT       := ./include/libft_/libft.a
PRINTF      := ./include/printf_/libftprintf.a

SRCS        := $(shell find ./src -iname "*.c")
OBJS        := ${SRCS:.c=.o}

BONUS_SRCS  := $(shell find ./src_bonus -iname "*.c")
BONUS_OBJS  := ${BONUS_SRCS:.c=.o}

GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m


all: libmlx $(NAME)

bonus: libmlx $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(BONUS_OBJS) $(LIBS) $(LIBFT) $(PRINTF) -I ./include/so_long_bonus.h -o $(BONUS_NAME)
	@echo "${GREEN}So_long_bonus compilation OK${RESET}"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(LIBFT) $(PRINTF) -I ./include/so_long.h -o $(NAME)
	@echo "${GREEN}So_long compilation OK${RESET}"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

libmlx: $(LIBMLX)/build/libmlx42.a

$(LIBMLX)/build/libmlx42.a:
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4

clean:
	@rm -rf $(OBJS) $(BONUS_OBJS)
	@rm -rf $(LIBMLX)/build
	@echo "${YELLOW}All objects removed${RESET}"

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo "${RED}So_long removed${RESET}"
	
download_mlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		$(GIT_MLX); \
		echo "${GREEN}MLX42 descargado en $(LIBMLX)${RESET}"; \
	else \
		echo "${YELLOW}MLX42 ya existe en $(LIBMLX)${RESET}"; \
	fi

clean_mlx:
	@if [ -d "$(LIBMLX)" ]; then \
		rm -rf $(LIBMLX); \
		echo "${RED}MLX42 eliminado de $(LIBMLX)${RESET}"; \
	else \
		echo "${YELLOW}MLX42 no está presente en $(LIBMLX)${RESET}"; \
	fi

re: fclean all

.PHONY: all, clean, fclean, re, libmlx, bonus
