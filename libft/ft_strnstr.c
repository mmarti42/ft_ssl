/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:24:15 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/23 12:54:08 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	size_t	n;
	int		tmp;
	char	*res;

	n = 0;
	tmp = 0;
	if (!*needle)
		return ((char *)haystack);
	while (n < len && haystack[n] != 0)
	{
		i = 0;
		while (haystack[n] != needle[i] && n < len && haystack[n] != 0)
			n++;
		if (haystack[n] == needle[i])
		{
			res = ((char *)&haystack[n]);
			while (haystack[n] == needle[i] && n++ < len && needle[i] != 0)
				i++;
			if (needle[i] == 0)
				return (res);
			n = ++tmp;
		}
	}
	return (0);
}
