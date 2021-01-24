/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:54:43 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/12 17:54:50 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *str, int ch)
{
	char	*ar;
	size_t	size;

	ar = (char *)str;
	size = ft_strlen(str);
	ar += size;
	size += 1;
	while (size--)
	{
		if (*ar == ch)
			return (ar);
		ar--;
	}
	return (0);
}
