/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5step.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:28:24 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/31 15:28:26 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static uint32_t	f1(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & y) | ((~x) & z));
}

static uint32_t	f2(uint32_t x, uint32_t y, uint32_t z)
{
	return ((x & z) | (y & (~z)));
}

static uint32_t	f3(uint32_t x, uint32_t y, uint32_t z)
{
	return (x ^ y ^ z);
}

static uint32_t	f4(uint32_t x, uint32_t y, uint32_t z)
{
	return (y ^ (x | (~z)));
}

void			md5setfg(uint32_t *f, uint32_t *g, int i, uint32_t *hash)
{
	if (i < 16)
	{
		*f = f1(hash[B], hash[C], hash[D]);
		*g = i;
	}
	else if (i < 32)
	{
		*f = f2(hash[B], hash[C], hash[D]);
		*g = (i * 5 + 1) % 16;
	}
	else if (i < 48)
	{
		*f = f3(hash[B], hash[C], hash[D]);
		*g = (i * 3 + 5) % 16;
	}
	else
	{
		*f = f4(hash[B], hash[C], hash[D]);
		*g = (7 * i) % 16;
	}
}
