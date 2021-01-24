/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:46:05 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/04 21:28:51 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	int		len;
	char	*c;

	if (!str)
		return (0);
	len = ft_strlen(str);
	c = (char *)malloc(len * sizeof(*str) + 1);
	if (!c)
		return (0);
	while (*str != '\0')
		*c++ = *str++;
	*c = '\0';
	return (c - len);
}
