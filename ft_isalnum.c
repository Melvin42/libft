#include "libft.h"

/*
** Checks for an alphanumeric character.
*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
