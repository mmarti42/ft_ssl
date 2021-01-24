/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:45:15 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/11 14:47:42 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char const *haystack, char const *needle)
{
	char const *res;
	char const *ndl;

	if (*needle == '\0')
		return (char *)(haystack);
	ndl = needle;
	while (*ndl != '\0' && *haystack != '\0')
	{
		if (*ndl == *haystack)
			res = haystack;
		while (*ndl == *haystack)
		{
			ndl++;
			haystack++;
			if (*ndl == '\0')
				return (char *)(res);
		}
		if (ndl != needle)
			haystack = ++res;
		ndl = needle;
		haystack++;
	}
	return (0);
}
