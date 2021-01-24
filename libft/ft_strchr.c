/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:17:26 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/09 18:17:28 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strchr(const char *str, int ch)
{
	char *res;

	if (ch == '\0')
		return (char *)(str + ft_strlen(str));
	res = ft_memchr(str, ch, ft_strlen(str) + 1);
	return (res);
}
