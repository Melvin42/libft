SRCS	= ft_isalpha.c ft_memccpy.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_atoi.c ft_isascii.c ft_memcpy.c ft_split.c ft_strlcat.c ft_strrchr.c ft_bzero.c ft_isdigit.c ft_memset.c ft_strchr.c ft_strlcpy.c ft_tolower.c ft_isalnum.c ft_isprint.c ft_strmapi.c ft_putchar_fd.c ft_strdup.c ft_strlen.c ft_toupper.c ft_strtrim.c ft_substr.c

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

AR		= ar rc

GCC		= gcc

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o) 

$(NAME):	$(OBJS) 
			$(AR) $(NAME) $(OBJS)
			
all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
