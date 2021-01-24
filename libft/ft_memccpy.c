/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:56:06 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/12 15:11:07 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*dest;
	unsigned char	*source;
	size_t			counter;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	ch = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		dest[counter] = source[counter];
		if (dest[counter] == ch)
			return (dst + 1);
		counter++;
	}
	return (0);
}
