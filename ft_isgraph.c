#include "libft.h"

/*
** Checks for any printable character except space.
*/

int	ft_isgraph(int c)
{
	return (ft_isprint(c) && !ft_isblank(c));
}
