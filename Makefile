# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pba <pba@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/09 11:34:20 by pba               #+#    #+#              #
#    Updated: 2015/10/07 09:36:36 by pba              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: mkdir_obj, clean

.SUFFIXES:

NAME		= ft_select
CFLAGS		= -Wall -Wextra -Werror
HPATH_SEL	= includes/
HPATH_LIBFT = libft/includes/
SPATH		= src/
OPATH		= obj/

SRC			= dlist_new.c \
			  dlist_append.c \
			  dlist_block_max.c \
			  dlist_delete_one.c \
			  ft_select.c \
			  tinit.c \
			  traw.c \
			  treset.c \
			  tstop.c \
			  tcont.c \
			  tget_key.c \
			  tsignal.c \
			  tselected.c \
			  tselected_all.c \
			  tdisplay.c \
			  tresize.c \
			  tmove.c \
			  tclear.c \
			  tcm.c \
			  tho.c \
			  tse.c \
			  tso.c \
			  tue.c \
			  tus.c \
			  tve.c \
			  tvi.c \
			
OBJ			= $(SRC:%.c=$(OPATH)%.o)

all: mkdir_obj $(NAME)

$(NAME): $(OBJ)
	@echo "\033[32;01mObject files created.\033[0m"
	@echo "\033[36;01mCompiling libft...\033[0m"
	@make re -C libft
	@echo "\033[32;01mlibft.a created.\033[0m"
	@gcc  -o $(NAME) $(OBJ) -lncurses -L./libft/ -lft
	@echo "\033[32;01mLink done.\033[0m"

$(OPATH)%.o: $(SPATH)%.c
	@gcc $(CFLAGS) -c $< -I $(HPATH_SEL) -I $(HPATH_LIBFT) -o $@

mkdir_obj:
	@mkdir -p $(OPATH)
	@echo "\033[32;01mobj/ folder created.\033[0m"

clean:
	@rm -rf $(OBJ)
	@echo "Objects deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted."

re: fclean all
