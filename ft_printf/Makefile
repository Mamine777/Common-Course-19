# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mokariou <mokariou@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 17:38:28 by mokariou          #+#    #+#              #
#    Updated: 2024/10/15 15:28:32 by mokariou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# # Name of the executable/library
# NAME = ft_printf

# # Compiler and flags
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# # Source and object files
# SRC = $(wildcard *.c)
# OBJ = $(SRC:.c=.o)
# AFILE = libftprintf.a

# # Colors (Magenta, Cyan, Yellow, Blue)
# MAGENTA = \033[35m
# CYAN = \033[36m
# YELLOW = \033[33m
# BLUE = \033[34m
# RESET = \033[0m

# # Enhanced FT_printf Logo with More Cool Colors
# LOGO = "\n${CYAN}███████╗████████╗    ${MAGENTA}████████╗██████╗ ${CYAN}████████╗███████╗\n\
# ${CYAN}██╔════╝╚══██╔══╝    ${MAGENTA}╚══██╔══╝██╔══██╗${CYAN}╚══██╔══╝██╔════╝\n\
# ${CYAN}███████╗   ██║       ${MAGENTA}   ██║   ██████╔╝   ${CYAN} ██║   █████╗  \n\
# ${CYAN}╚════██║   ██║       ${MAGENTA}   ██║   ██╔═══╝    ${CYAN} ██║   ██╔══╝  \n\
# ${CYAN}███████║   ██║       ${MAGENTA}   ██║   ██║        ${CYAN} ██║   ███████╗\n\
# ${CYAN}╚══════╝   ╚═╝       ${MAGENTA}   ╚═╝   ╚═╝        ${CYAN} ╚═╝   ╚══════╝\n\
# ${RESET}"

# # Targets
# all: $(AFILE) $(NAME)

# # Creating the static library
# $(AFILE): $(OBJ)
# 	@echo "${BLUE}Creating static library...${RESET}"
# 	ar rc $(AFILE) $(OBJ)
# 	ranlib $(AFILE)
# 	@echo "${MAGENTA}Static library created successfully!${RESET}"

# # Creating the executable
# $(NAME): $(OBJ)
# 	@echo "$(LOGO)"
# 	@echo "${YELLOW}Compiling executable...${RESET}"
# 	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
# 	@echo "${MAGENTA}Compilation successful! Executable created.${RESET}"

# # Object files generation
# %.o: %.c
# 	@echo "${CYAN}Compiling $< ...${RESET}"
# 	$(CC) $(CFLAGS) -c $< -o $@

# # Clean object files
# clean:
# 	@echo "${BLUE}Removing object files...${RESET}"
# 	rm -f $(OBJ)
# 	@echo "${MAGENTA}Object files removed.${RESET}"

# # Full clean: remove object files, static library, and executable
# fclean: clean
# 	@echo "${BLUE}Removing static library and executable...${RESET}"
# 	rm -f $(AFILE) $(NAME)
# 	@echo "${MAGENTA}Cleaned up!${RESET}"

# # Rebuild everything
# re: fclean all

NAME = ft_printf

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_address.c ft_print_hex.c ft_printf.c /
ft_unsigned.c printnum.c putstr.c

OBJ = $(SRC:.c=.o)

AFILE = libftprintf.a

all: $(AFILE) $(NAME)

$(AFILE): $(OBJ)
	ar rc $(AFILE) $(OBJ)
	ranlib $(AFILE)

$(NAME): $(OBJ)
	@echo "Compiling .."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Done !"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Remove .o  ..."
	rm -f $(OBJ)
	@echo "Done !"

fclean: clean
	@echo "Remove lib ..."
	rm -f $(AFILE) $(NAME)
	@echo "Done !"

re: fclean all
