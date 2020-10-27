#include "libft.h"

/*
** Checks for white-space characters. In the "C" and "POSIX"  locales,
** these are : space, form-feed ('\f'), newline ('\n'), carriage return ('\r'),
** horizontal tab ('\t'), and vertical tab ('\v').
*/

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
