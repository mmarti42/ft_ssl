/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:16:38 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/31 15:16:43 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

uint32_t	rotate_right(uint32_t num, int n)
{
	return (num >> n) | (num << (32 - n));
}

uint32_t	rotate_left(uint32_t num, int n)
{
	return (num << n) | (num >> (32 - n));
}

uint32_t	b_swap32(uint32_t x)
{
	return ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >> 8)
	| (((x) & 0x0000ff00u) << 8) | (((x) & 0x000000ffu) << 24));
}

void		append_byte(t_buf *data, uint8_t byte)
{
	if (data->siz == data->memsize)
		data->buf = realloc(data->buf, data->memsize += SBLOCK);
	data->buf[data->siz] = byte;
	(data->siz)++;
}

uint64_t	b_swap64(uint64_t val)
{
	val = ((val << 8) & 0xFF00FF00FF00FF00ULL) |
		((val >> 8) & 0x00FF00FF00FF00FFULL);
	val = ((val << 16) & 0xFFFF0000FFFF0000ULL) |
		((val >> 16) & 0x0000FFFF0000FFFFULL);
	return (val << 32) | (val >> 32);
}
