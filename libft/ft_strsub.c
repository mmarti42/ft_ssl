/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:30:24 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/15 23:30:25 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	dst = (char *)ft_memalloc(len + 1);
	if (!dst)
		return (NULL);
	while (len--)
		dst[i++] = s[start++];
	return (dst);
}
