/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:29:27 by melperri          #+#    #+#             */
/*   Updated: 2020/11/16 15:29:28 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Checks for any printable character which is not a space or an alphanumeric
** character.
*/

int	ft_ispunct(int c)
{
	return (ft_isprint(c) && (!ft_isblank(c) || !ft_isalnum(c)));
}
