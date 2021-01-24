/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:09:57 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 19:09:59 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *string)
{
	int counter;

	if (!string)
		return (0);
	counter = 0;
	while (*string++)
		counter++;
	return (counter);
}
