/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:42:58 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/11 19:44:04 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	digit;
	long int	sign;
	long int	prv;

	digit = 0;
	sign = 1;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		sign = (*str++ == '-' ? -1 : 1);
	while (*str == '0')
		str++;
	if (ft_strlenbr(str) > 19)
		return (sign == -1 ? 0 : -1);
	if (*str > '9' && *str < '0')
		return (0);
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		prv = digit;
		digit = digit * 10 + *str - 48;
		str++;
		if (prv > digit)
			return (sign == -1 ? 0 : -1);
	}
	return (digit * sign);
}
