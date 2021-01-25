SRCS	= ft_isblank.c \
		  ft_iscntrl.c \
		  ft_isgraph.c \
		  ft_ispunct.c \
		  ft_isspace.c \
		  ft_islower.c \
		  ft_isupper.c \
		  ft_isxdigit.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memcpy_rev.c \
		  ft_memccpy.c \
		  ft_memmove.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_strlen.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strcpy.c \
		  ft_str_is_alpha.c \
		  ft_str_is_lowercase.c \
		  ft_str_is_numeric.c \
		  ft_str_is_uppercase.c \
		  ft_strlowcase.c \
		  ft_strupcase.c \
		  ft_strchr.c \
		  ft_strrchr.c \
		  ft_strncmp.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_atoi.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_checkbase.c \
		  ft_stopatoi.c \
		  ft_findchar.c \
		  ft_convert_base.c \
		  ft_atoi_base.c \
		  ft_itoa_base.c \
		  ft_utoa_base.c \
		  ft_utoa_base.c \
		  ft_ultoa_base.c \
		  get_next_line.c \
		  get_next_line_utils.c \

SRCS_BONUS = ft_lstnew.c \
		   ft_lstadd_front.c \
		   ft_lstsize.c \
		   ft_lstlast.c \
		   ft_lstclear.c \
		   ft_lstiter.c \
		   ft_lstadd_back.c \
		   ft_lstdelone.c \
		   ft_lstmap.c \
		   get_next_line_bonus.c \
		   get_next_line_utils_bonus.c \

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libft.a

AR = ar rc

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) 

all: ${NAME}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
 
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: .c.o all clean fclean re bonus
