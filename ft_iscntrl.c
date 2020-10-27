#include "libft.h"

/*
** Checks for a control character.
*/

int	ft_iscntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}
