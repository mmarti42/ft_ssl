/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:32:46 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/06 16:32:48 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_insert(char *str, char *todel, char *toins)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	fpart;

	len1 = ft_strlen(str) - ft_strlen(todel);
	len2 = ft_strlen(toins);
	fpart = ft_strstr(str, todel) - str;
	res = (char *)ft_memalloc(len1 + len2 + 1);
	ft_memcpy(res, str, fpart);
	ft_memcpy(&res[fpart], toins, len2);
	ft_memcpy(&res[fpart + len2], &str[fpart + ft_strlen(todel)],
			ft_strlen(&str[fpart + ft_strlen(todel)]));
	return (res);
}
