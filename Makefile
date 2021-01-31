# ------------  PROJECT  ----------------------------------------------------- #

NAME :=	ft_ssl

# ------------  FLAGS  ------------------------------------------------------- #

FLAGS := -g -Wall -Wextra -Werror

# ------------  SOURCE FILES  ------------------------------------------------ #

SOURCES := ft_ssl.c \
			hash.c\
			md5.c\
			md5setfd.c\
			utils.c\
			sha256.c\
			utils2.c

# ------------  DIRECTORIES  ------------------------------------------------- #

DIR_O := obj
DIR_S := src
INCLUDE_DIR = includes

# ------------  LIBFT  ------------------------------------------------------- #

LIBFT_DIR := libft
LIB_INCLUDE_DIR := $(LIBFT_DIR)/includes
LIB_HEADERS := \
			$(wildcard $(LIB_INCLUDE_DIR)/*.h) \

# ------------  INCLUDE FILES  ----------------------------------------------- #

INCLUDES := \
			-I $(INCLUDE_DIR) \
			-I $(LIB_INCLUDE_DIR) \

# ------------  FILEPATHS  --------------------------------------------------- #

SRCS := $(addprefix $(DIR_S)/,$(SOURCES))
OBJS := $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
LIBFT := $(addsuffix .libft , $(LIBFT_DIR)/)

# ------------  RULES  ------------------------------------------------------- #

.PHONY: all clean fclean re

%.libft:  $(LIB_HEADERS)
	make -C $*

LIBS_INCLUDED = libft/libftprintf.a

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT_DIR)/libftprintf.a $(OBJS)
	@echo "\033[32;01mCompiling...\033[0m"
	gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIBS_INCLUDED)
	@echo "\033[32;01mbinary is ready\033[0m"

$(OBJS): $(DIR_O)/%.o: $(DIR_S)/%.c $(wildcard $(INCLUDE_DIR)/*.h) | $(DIR_O)
	gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

$(DIR_O):
	mkdir -p $(DIR_O)
	mkdir -p $(DIR_O)/$(VALIDATOR_DIR)
	mkdir -p $(DIR_O)/$(ALGORITHM_DIR)

clean:
	@echo "\033[34mDeleting lem_in o-files\033[0m"
	/bin/rm -rf $(DIR_O)
	make clean --directory $(LIBFT_DIR)

fclean: clean
	@echo "\033[34mDeleting binary\033[0m"
	/bin/rm -f $(NAME)
	make fclean --directory $(LIBFT_DIR)

re: fclean all