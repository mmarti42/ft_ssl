/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:41:29 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/09 19:41:31 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(char const *str1, char const *str2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	if (n == 0)
		return (0);
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 == *s2 && --n)
	{
		if (*s1 == '\0' || *s2 == '\0')
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
