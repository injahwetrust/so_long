# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvaujour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 12:30:28 by bvaujour          #+#    #+#              #
#    Updated: 2023/02/14 12:33:38 by bvaujour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR=\033[0m
OK_COLOR=\033[32;01m
ERROR_COLOR=\033[31;01m
WARN_COLOR=\033[33;01m

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING=$(WARN_COLOR)[WARNINGS]$(NO_COLOR)

### INCLUDES ###

INCLUDES	= includes/so_long.h libft/ft_printf.h includes/so_long_bonus.h libft/libft.h

LIBS		= -L./libft -lft -L./mlx -lmlx_Linux -lXext -lX11 -lm -lz

### SOURCES ###

FILES = end.c error0.c main.c map_check.c moves.c render.c check.c

FILES_B = edit_bonus1.c edit_bonus2.c graphic_bonus1.c graphic_bonus2.c graphic_bonus3.c initend_bonus.c map_check_bonus1.c map_check_bonus2.c move_bonus.c so_long_bonus.c check_bonus.c

### MACROS ###

DIRPATH =	$(sh pwd)
SRCPATH	=	$(DIRPATH)src/
SRCBPATH	=	$(DIRPATH)src_bonus/
SRC	=	$(addprefix $(SRCPATH), $(FILES))
SRC_B	=	$(addprefix $(SRCBPATH), $(FILES_B))

LIBFT = libft/libft.a
MLX = mlx/libmlx_Linux.a
NAME 	= so_long
NAME_B	= so_long_bonus
OBJ	= $(SRC:.c=.o)
OBJ_B	= $(SRC_B:.c=.o)

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra -D BUFFER_SIZE=1 

### RULES ###

all : $(NAME)

$(NAME) :  $(MLX) $(LIBFT) $(OBJ) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

bonus : $(NAME_B)

$(NAME_B): $(MLX) $(LIBFT) $(OBJ_B) $(INCLUDES_B)
	$(CC) $(CFLAGS) $(OBJ_B) $(LIBS) -o $(NAME_B)


$(LIBFT) :
	make -C libft
	
$(MLX) :
	git clone https://github.com/42Paris/minilibx-linux.git mlx
	make -C mlx

test	: $(NAME)
	@echo "\033[33mTesting FALSE EXTENSION\033[00m"
	@echo "\n"
	@cat maps/error/falseext.txt
	@echo "\033[32m\n"
	valgrind ./$(NAME) maps/error/falseext.txt
	@echo "\n"
	@echo "\033[33mTesting BOTTOM EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderbot.ber	
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderbot.ber
	@echo "\n"
	@echo "\033[33mTesting LEFT EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderleft.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderleft.ber
	@echo "\n"
	@echo "\033[33mTesting RIGHT EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderright.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderright.ber
	@echo "\n"
	@echo "\033[33mTesting TOP EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/bordertop.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/bordertop.ber
	@echo "\n"
	@echo  "\033[33mTesting COLLECTIBLE NOT REACHABLE\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Cnotrechable.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Cnotrechable.ber
	@echo "\n"
	@echo "\033[33mTesting EXIT NON REACHABLE\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Enotrechable.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Enotrechable.ber
	@echo "\n"
	@echo "\033[33mTesting DOUBLE EXIT\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleE.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleE.ber
	@echo "\n"
	@echo "\033[33mTesting DOUBLE HERO\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleP.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleP.ber
	@echo "\n"
	@echo "\033[33mTesting NEWLINES IN MAP\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/newlines.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/newlines.ber
	@echo "\n"
	@echo "\033[33mTesting NO EXIT\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noexit.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noexit.ber
	@echo "\n"
	@echo "\033[33mTesting NO PERSO\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noperso.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noperso.ber
	@echo "\n"
	@echo "\033[33mTesting MAP NOT RECTANGLE\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/recterror.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/recterror.ber
	@echo "\n"
	@echo "\033[33mTesting WRONG KEY\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/wrongkey.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/wrongkey.ber
	@echo "\n"
	
testbonus	: $(NAME_B)
	@echo "\033[33mTesting FALSE EXTENSION\033[00m"
	@echo "\n"
	@cat maps/error/falseext.txt
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) maps/error/falseext.txt
	@echo "\n"
	@echo "\033[33mTesting BOTTOM EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderbot.ber	
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderbot.ber
	@echo "\n"
	@echo "\033[33mTesting LEFT EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderleft.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderleft.ber
	@echo "\n"
	@echo "\033[33mTesting RIGHT EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderright.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/borderright.ber
	@echo "\n"
	@echo "\033[33mTesting TOP EDGE NOT CLOSED\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/bordertop.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/bordertop.ber
	@echo "\n"
	@echo  "\033[33mTesting COLLECTIBLE NOT REACHABLE\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Cnotrechable.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Cnotrechable.ber
	@echo "\n"
	@echo "\033[33mTesting EXIT NON REACHABLE\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Enotrechable.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/Enotrechable.ber
	@echo "\n"
	@echo "\033[33mTesting DOUBLE EXIT\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleE.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleE.ber
	@echo "\n"
	@echo "\033[33mTesting DOUBLE HERO\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleP.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/doubleP.ber
	@echo "\n"
	@echo "\033[33mTesting NEWLINES IN MAP\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/newlines.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/newlines.ber
	@echo "\n"
	@echo "\033[33mTesting NO EXIT\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noexit.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noexit.ber
	@echo "\n"
	@echo "\033[33mTesting NO PERSO\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noperso.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/noperso.ber
	@echo "\n"
	@echo "\033[33mTesting MAP NOT RECTANGLE\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/recterror.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/recterror.ber
	@echo "\n"
	@echo "\033[33mTesting WRONG KEY\033[00m"
	@echo "\n"
	@cat /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/wrongkey.ber
	@echo "\033[32m\n"
	valgrind ./$(NAME_B) /mnt/nfs/homes/bvaujour/projets/so_long/maps/error/wrongkey.ber
	@echo "\n"
	
clean:
	make clean -C libft
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	make fclean -C libft
	rm -rf mlx
	rm $(NAME) $(NAME_B)
	
re: fclean all

.PHONY: clean fclean re
