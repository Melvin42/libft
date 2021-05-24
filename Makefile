## Name of Project

NAME = libft.a

## Color for compilating (pink)

COLOR = \0033[1;35m

## List of Directories

INC_DIR = inc
OBJ_DIR = obj
SRC_DIR = src

# Add dirs here

ALLOC_DIR	= alloc
CONV_DIR	= conv
FILE_DIR	= file
IS_DIR		= is
LST_DIR		= lst
MEM_DIR		= mem
PUT_DIR		= put
STR_DIR		= str

## Compilating Utilities

#DEBUG = -g3 -fsanitize=address

FLAGS = -Wall -Wextra -Werror #$(DEBUG) -D_REENTRANT

INC = $(./$(INC_DIR)/-I%.h)

CC = clang $(FLAGS) $(INC)

AR = ar rc

ALLOC_FT = ft_calloc

CONV_FT  = ft_tolower ft_toupper ft_checkbase ft_stopatoi ft_findchar \
		   ft_convert_base ft_atoi ft_atoi_base ft_itoa ft_itoa_base \
		   ft_utoa_base ft_utoa_base ft_ultoa_base

FILE_FT  = get_next_line

IS_FT	 = ft_isblank ft_iscntrl ft_isgraph ft_ispunct ft_isspace \
		   ft_islower ft_isupper ft_isxdigit ft_isalpha ft_isdigit ft_isalnum \
		   ft_isascii ft_isprint

LST_FT	 = ft_lstnew ft_lstadd_front ft_lstsize \
		   ft_lstlast ft_lstclear ft_lstiter ft_lstadd_back ft_lstdelone \
		   ft_lstmap

MEM_FT	 = ft_memset ft_bzero ft_memcpy ft_memcpy_rev \
		   ft_memccpy ft_memmove ft_memchr ft_memcmp

PUT_FT	 = ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd

STR_FT	 = ft_split ft_strdup ft_str_is_numeric ft_strlcat ft_strnstr \
		   ft_strlowcase ft_strupcase ft_strchr ft_str_is_alpha \
		   ft_str_is_uppercase ft_strlcpy ft_strmapi ft_strrchr ft_substr \
		   ft_strcpy ft_str_is_lowercase ft_strjoin ft_strlen ft_strncmp \
		   ft_strtrim

## List of Utilities

SRC = $(ALLOC_FT:%=$(SRC_DIR)/$(ALLOC_DIR)/%.c) \
	$(CONV_FT:%=$(SRC_DIR)/$(CONV_DIR)/%.c) \
	$(FILE_FT:%=$(SRC_DIR)/$(FILE_DIR)/%.c) \
	$(IS_FT:%=$(SRC_DIR)/$(IS_DIR)/%.c) \
	$(LST_FT:%=$(SRC_DIR)/$(LST_DIR)/%.c) \
	$(MEM_FT:%=$(SRC_DIR)/$(MEM_DIR)/%.c) \
	$(PUT_FT:%=$(SRC_DIR)/$(PUT_DIR)/%.c) \
	$(STR_FT:%=$(SRC_DIR)/$(STR_DIR)/%.c) \
	$(PRINTF_FT:%=$(SRC_DIR)/$(PRINTF_DIR)/%.c)

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

OBJ_DIRS = $(OBJ_DIR) \
	$(ALLOC_DIR:%=$(OBJ_DIR)/%) \
	$(CONV_DIR:%=$(OBJ_DIR)/%) \
	$(FILE_DIR:%=$(OBJ_DIR)/%) \
	$(IS_DIR:%=$(OBJ_DIR)/%) \
	$(LST_DIR:%=$(OBJ_DIR)/%) \
	$(MEM_DIR:%=$(OBJ_DIR)/%) \
	$(PUT_DIR:%=$(OBJ_DIR)/%) \
	$(STR_DIR:%=$(OBJ_DIR)/%) \
	$(PRINTF_DIR:%=$(OBJ_DIR)/%)

## Rules of Makefile

all: $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;30m[All OK]\0033[1;37m"

$(OBJ_DIRS):
	@mkdir -p $@
	@echo "$(COLOR)$@ \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@echo "$(COLOR)Creating :\t\0033[0;32m$@\0033[1;37m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) -c $< -o $@
	@echo "$(COLOR)$(@:$(OBJ_DIR)/%=%) \033[100D\033[40C\0033[1;32m[Compiled]\0033[1;37m"

$(NAME): $(OBJ_DIRS) $(SRC) $(INC)
	@$(MAKE) -j -s $(OBJ) 
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"
	@$(AR) $(NAME) $(OBJ)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;32m[Created]\0033[1;37m"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR)Objects \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOR)$(NAME) \033[100D\033[40C\0033[1;31m[Removed]\0033[1;37m"

re: fclean all

define print_aligned_coffee
    @t=$(NAME); \
	l=$${#t};\
	i=$$((8 - l / 2));\
	echo "         \0033[1;32m\033[3C\033[$${i}CAnd Your program \"$(NAME)\" "
endef

coffee: all clean
	@echo ""
	@echo "                            {"
	@echo "                         {   }"
	@echo "                          }\0033[1;34m_\0033[1;37m{ \0033[1;34m__\0033[1;37m{"
	@echo "                       \0033[1;34m.-\0033[1;37m{   }   }\0033[1;34m-."
	@echo "                      \0033[1;34m(   \0033[1;37m}     {   \0033[1;34m)"
	@echo "                      \0033[1;34m| -.._____..- |"
	@echo "                      |             ;--."
	@echo "                      |            (__  \ "
	@echo "                      |             | )  )"
	@echo "                      |   \0033[1;96mCOFFEE \0033[1;34m   |/  / "
	@echo "                      |             /  / "
	@echo "                      |            (  / "
	@echo "                      \             | "
	@echo "                        -.._____..- "
	@echo ""
	@echo ""
	@echo "\0033[1;32m\033[3C                Take Your Coffee"
	$(call print_aligned_coffee)

.PHONY: all clean fclean re coffee
