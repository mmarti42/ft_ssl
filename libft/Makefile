# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarti <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 14:18:02 by mmarti            #+#    #+#              #
#    Updated: 2019/04/12 14:18:07 by mmarti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_O = objs

SRC = ft_memalloc.c\
	ft_strcat.c\
	ft_strncmp.c\
	ft_memccpy.c\
	ft_strchr.c\
	ft_strncpy.c\
    ft_atoi.c\
	ft_bzero.c\
	ft_memcmp.c\
	ft_strcmp.c\
    ft_dcount.c\
	ft_memcpy.c\
	ft_strcpy.c\
	ft_strnlen.c\
    ft_isalnum.c\
	ft_strnstr.c\
    ft_isalpha.c\
	ft_memmove.c\
	ft_strdup.c\
	ft_strrchr.c\
    ft_isascii.c\
	ft_memset.c\
	ft_strrev.c\
    ft_isdigit.c\
	ft_putchar.c\
	ft_strsplit.c\
    ft_isprint.c\
	ft_putchar_fd.c\
	ft_strstr.c\
    ft_itoa.c\
	ft_putendl.c\
	ft_strjoin.c\
	ft_strsub.c\
    ft_putendl_fd.c\
	ft_strtrim.c\
    ft_putnbr.c\
	ft_strlen.c\
	ft_tolower.c\
    ft_putnbr_fd.c\
	ft_toupper.c\
    ft_putstr.c\
	ft_sqrt.c\
    ft_putstr_fd.c\
	ft_strnchr.c\
    ft_strwlen.c\
	ft_insert.c\
	ft_count_str.c\
	ft_strclen.c\
	ft_strtok.c\
    get_next_line.c\
	ft_xmalloc.c\
	parse_opt.c\
	ft_lstins.c\
	ft_lstdel.c

OBJ = $(addprefix $(DIR_O)/,$(SRC:.c=.o))

HEAD = .

all: $(NAME)

$(NAME): mes $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[34mDone!\033[0m"

mes:
	@echo "\033[34mCompiling...\033[0m"

$(DIR_O):
	@mkdir -p $(DIR_O)

$(OBJ): $(DIR_O)/%.o: %.c $(wildcard $(HEAD)/*.h) | $(DIR_O)
	@gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

clean:
	/bin/rm -rf $(DIR_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all


