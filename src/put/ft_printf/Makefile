SRCS	= src/ft_printf.c \
		  src/ft_flags.c \
		  src/ft_pars_flags.c \
		  src/ft_printf_convert.c \
		  src/ft_printf_convert2.c \
		  src/ft_printf_string.c \
		  src/ft_printf_string2.c \
		  src/ft_printf_addr.c \
		  src/ft_printf_null_addr.c \
		  src/ft_printf_int_pos.c \
		  src/ft_printf_int_neg.c \
		  src/ft_printf_int_plus.c \
		  src/ft_printf_hexmin.c \
		  src/ft_printf_hexmin2.c \
		  src/ft_printf_hexmaj.c \
		  src/ft_printf_hexmaj2.c \
		  src/ft_printf_hex_long.c \
		  src/ft_printf_hex_ll.c \
		  src/ft_printf_hex_hh.c \
		  src/ft_printf_modifier.c \
		  src/ft_printf_short.c \
		  src/ft_printf_long.c \
		  src/ft_printf_ll.c \
		  src/ft_printf_hh.c \

CC = clang

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libftprintf.a

INC	= ../../inc/ft_printf.h \
	  ../../inc/ft_printf_struct.h \

AR = ar rcs

LIB = libft/libft.a

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

bonus: all

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(AR) $(NAME) $(OBJS) ./libft/*.o 

$(LIB):
	make -C ./libft/

clean:
	$(RM) $(OBJS)
	make clean -C ./libft/

fclean:	clean
	$(RM) $(NAME) $(LIB)

re:	fclean all

.PHONY: .c.o all clean fclean re bonus
