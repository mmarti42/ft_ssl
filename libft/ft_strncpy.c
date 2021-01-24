/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 01:19:42 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/06 01:19:44 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*dst;

	dst = dest;
	while (n-- && *src != '\0')
		*dst++ = *src++;
	if (*src == '\0')
		ft_bzero(dst, n + 1);
	return (dest);
}
