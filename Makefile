# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spalmer <spalmer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 23:28:44 by aghar             #+#    #+#              #
#    Updated: 2021/01/03 19:25:27 by spalmer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom
CC = clang
FILES = begin init error events grid vertex draw_line sector menu tools levels
LIBFT_DIR = libft/
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addprefix obj/, $(addsuffix .o, $(FILES)))
OBJ_LIST = $(addsuffix .o, $(FILES))
SDL_CFLAGS = $(shell sdl2-config --cflags)
SPEED = -O3  -g
FLAGS = -g #-Wall -Wextra -Werror
HEADERS = -I./includes -I./libft/includes

OS = $(shell uname)
ifeq ($(OS), Linux)
CGFLAGS = `sdl2-config --cflags --libs` -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
else
CGFLAGS = -framework OpenGL -framework AppKit
INCLUDES	=	-I./frameworks/SDL2.framework/Versions/A/Headers \
				-I./frameworks/SDL2_ttf.framework/Versions/A/Headers \
				-I./frameworks/SDL2_image.framework/Versions/A/Headers \
				-I./frameworks/SDL2_mixer.framework/Headers \
				-F./frameworks \
				-I./includes/reader.h
				
FRAMEWORKS	=	-F./frameworks \
				-rpath ./frameworks \
				-framework OpenGL -framework AppKit -framework OpenCl \
				-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
				-framework SDL2_mixer
endif

all: $(NAME)

.PHONY: all clean
.NOTPARALLEL: all $(NAME) clean fclean re 

$(NAME): libft/libft.a $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(SPEED) $(OBJ) $(CGFLAGS) $(FRAMEWORKS) libft/libft.a
libft/libft.a:
	@make -j3 -C $(LIBFT_DIR)
obj/%.o: src/%.c
	@$(CC) -o $@ $(FLAGS) $(SPEED) $(HEADERS) $(INCLUDES) -c $^
clean:
	@rm -f $(OBJ)
	@make -j3 -C libft/ clean
fclean:
	@rm -rf $(OBJ)
	@rm -f $(NAME)
	@make -j3 -C libft/ fclean
re: fclean all
