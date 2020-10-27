/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:22:21 by melperri          #+#    #+#             */
/*   Updated: 2020/10/12 12:57:59 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi() function converts the initial portion of the string pointed to
** by nptr to int.
*/

int ft_atoi(const char *nptr)
{
    unsigned long int	res;
    int	sign;
	
	res = 0;
	sign = 1;
    while (ft_isspace(*nptr))
		nptr++;
	*nptr == '-' ? sign *= -1 : sign;
	(*nptr == '+' || *nptr == '-') ? nptr++ : nptr;
    while (ft_isdigit(*nptr))
    {
        res = res * 10 + (*nptr - 48);
        nptr++;
    }
	if (res > LONG_MAX && sign == -1)
		return (0);
	else if (res > LONG_MAX && sign == 1)
		return (-1);
	else
		return (res * sign);
}
/*
** int	main(int ac, const char **av)
** {
** 	(void)ac;
** 	printf("atoi   : %d\n", atoi(av[1]));
** 	printf("ft_atoi: %d\n", ft_atoi(av[1]));
** 	return (0);
** }
*/
