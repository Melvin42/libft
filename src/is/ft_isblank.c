/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 02:12:52 by melperri          #+#    #+#             */
/*   Updated: 2020/11/18 02:12:53 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

/*
** Checks for a blank character; that is, a space or a tab.
*/

int	ft_isblank(int c)
{
	return (c == ' ' || c == '\t');
}
