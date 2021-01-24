/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:11:23 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/20 17:11:32 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t st;
	size_t e;

	if (!s)
		return (0);
	st = 0;
	e = ft_strlen(s) - 1;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (s[st] == 0)
		return (ft_strsub(s, st, 0));
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && e > 0)
		e--;
	return (ft_strsub(s, st, e - st + 1));
}
