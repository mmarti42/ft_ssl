/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 04:09:32 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/16 04:09:34 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	long int	nb;
	int			sign;
	size_t		len;
	char		*res;

	nb = n;
	sign = 0;
	len = ft_dcount(nb);
	if (nb < 0)
	{
		sign = 1;
		nb = -nb;
	}
	if (!(res = (char *)ft_memalloc(len + 1)))
		return (0);
	if (nb == 0)
		res[0] = '0';
	while (nb != 0)
	{
		res[--len] = '0' + nb % 10;
		nb /= 10;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}
