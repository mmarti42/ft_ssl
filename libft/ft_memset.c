/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:55:35 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 17:56:29 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *destination, int c, size_t n)
{
	char *dest;

	dest = destination;
	while (n--)
		*dest++ = c;
	return (destination);
}
