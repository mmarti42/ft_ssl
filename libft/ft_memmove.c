/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:02:27 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 19:02:30 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	char		*dest;
	const char	*src;

	src = source;
	dest = destination;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		src += n - 1;
		dest += n - 1;
		while (n--)
			*dest-- = *src--;
	}
	return (destination);
}
