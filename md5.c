#include "ft_ssl.h"

void	md5align(t_buf *data)
{
	append_byte(data, 128);

	while (data->siz % 64 != 56)
		append_byte(data, 0);
}

void md5_init(uint32_t *v)
{
	v[A] = 0x67452301;
	v[B] = 0xEFCDAB89;
	v[C] = 0x98BADCFE;
	v[D] = 0x10325476;
}

void	md5prepare(t_buf *data)
{
	uint64_t bitlen;
	
	bitlen = data->siz * 8;
	md5align(data);
	*(uint64_t *)(data->buf + data->siz) = bitlen;
	data->siz += 8;
	data->hash = (uint32_t *)xmalloc((data->hash_size = 4) * sizeof(uint32_t));
	md5_init(data->hash);
}

uint32_t *md5(t_buf *data)
{
	uint32_t v[4];
	size_t	ct;
	int i;

	ct = 0;
	md5prepare(data);
	while (ct < data->siz)
	{
		i = 0;
		v[A] = (data->hash)[A];
		v[B] = (data->hash)[B];
		v[C] = (data->hash)[C];
		v[D] = (data->hash)[D];
		while (i < 64)
		{
			md5step((uint32_t *)(data->buf + ct), v, i);
			i++;
		}
		(data->hash)[A] += v[A];
		(data->hash)[B] += v[B];
		(data->hash)[C] += v[C];
		(data->hash)[D] += v[D];
		ct += 64;
	}
	return (swap_bytes_order(data->hash, data->hash_size));
}
