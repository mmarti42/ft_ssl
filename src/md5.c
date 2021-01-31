/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:13:34 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/31 15:13:37 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "md5.h"

void		md5_init(uint32_t *hash)
{
	hash[0] = 0x67452301;
	hash[1] = 0xEFCDAB89;
	hash[2] = 0x98BADCFE;
	hash[3] = 0x10325476;
}

void		md5prepare(t_buf *data)
{
	uint64_t	bitlen;

	data->name = "MD5";
	bitlen = data->siz * 8;
	align(data);
	*(uint64_t *)(data->buf + data->siz) = bitlen;
	data->siz += 8;
	data->hash_size = 4;
	data->hash = (uint32_t *)xmalloc(data->hash_size * sizeof(uint32_t));
	md5_init(data->hash);
}

void		md5step(uint32_t *m, uint32_t *hash, int i)
{
	uint32_t f;
	uint32_t g;

	md5setfg(&f, &g, i, hash);
	f = f + hash[A] + g_k[i] + m[g];
	hash[A] = hash[D];
	hash[D] = hash[C];
	hash[C] = hash[B];
	hash[B] = hash[B] + rotate_left(f, g_s[i]);
}

uint32_t	*md5(t_buf *data)
{
	uint32_t	v[4];
	size_t		ct;
	int			i;

	ct = 0;
	md5prepare(data);
	while (ct < data->siz)
	{
		i = -1;
		ft_memcpy(v, data->hash, sizeof(uint32_t) * data->hash_size);
		while (++i < 64)
			md5step((uint32_t *)(data->buf + ct), v, i);
		(data->hash)[0] += v[A];
		(data->hash)[1] += v[B];
		(data->hash)[2] += v[C];
		(data->hash)[3] += v[D];
		ct += 64;
	}
	return (swap_bytes_order(data->hash, data->hash_size));
}
