#include "ft_ssl.h"

void md5_init(uint32_t *v)
{
	v[A] = 0x67452301;
	v[B] = 0xEFCDAB89;
	v[C] = 0x98BADCFE;
	v[D] = 0x10325476;
}

// uint64_t b_swap64(uint64_t x)
// {
// 	const uint32_t high_part = htonl((uint32_t)(x >> 32));
//     const uint32_t low_part = htonl((uint32_t)(x & 0xFFFFFFFFLL));
// 	return ((uint64_t)(low_part) << 32) | high_part;
// }

uint64_t	b_swap64(uint64_t val)
{
	val = ((val << 8) & 0xFF00FF00FF00FF00ULL) |
		((val >> 8) & 0x00FF00FF00FF00FFULL);
	val = ((val << 16) & 0xFFFF0000FFFF0000ULL) |
		((val >> 16) & 0x0000FFFF0000FFFFULL);
	return (val << 32) | (val >> 32);
}

void	md5prepare(t_buf *data)
{
	uint64_t bitlen;
	
	data->name = "MD5";
	bitlen = data->siz * 8;
	align(data);
	*(uint64_t *)(data->buf + data->siz) = bitlen;
	data->siz += 8;
}

uint32_t *md5(t_buf *data)
{
	uint32_t v[4];
	size_t	ct;
	int i;

	ct = 0;
	md5prepare(data);
	data->hash = (uint32_t *)xmalloc((data->hash_size = 4) * sizeof(uint32_t));
	md5_init(data->hash);
	while (ct < data->siz)
	{
		i = -1;
		ft_memcpy(v, data->hash, data->hash_size);
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
