/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 23:38:35 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/15 23:38:37 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	dst = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (0);
	while (*s1 != '\0')
		dst[i++] = *s1++;
	while (*s2 != '\0')
		dst[i++] = *s2++;
	return (dst);
}
