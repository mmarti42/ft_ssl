/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:20:55 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/09 18:20:57 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnchr(const char *str, int ch, size_t n)
{
	char *res;

	res = ft_memchr(str, ch, n);
	return (res);
}
