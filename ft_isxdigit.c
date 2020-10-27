#include "libft.h"

/*
** Checks for hexadecimal digits, that is, one of
** 0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F.
*/

int	ft_isxdigit(int c)
{
	return (ft_isdigit(c) || ((c >= 'a' && c <= 'f') \
			|| (c >= 'A' && c <= 'F')));
}
