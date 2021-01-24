/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:50:30 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 18:50:34 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	while (n--)
		*dst++ = *src++;
	return (destination);
}
