#include "ft_ssl.h"
#include "md5.h"

uint32_t f1(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & y) | ((~x) & z);
}

uint32_t f2(uint32_t x, uint32_t y, uint32_t z)
{
	return (x & z) | (y & (~z));
}

uint32_t f3(uint32_t x, uint32_t y, uint32_t z)
{
	return x ^ y ^ z;
}

uint32_t f4(uint32_t x, uint32_t y, uint32_t z)
{
	return y ^ (x | (~z));
}

void	md5step(uint32_t *m, uint32_t *hash, int i)
{
	uint32_t g, f;

	if (i < 16)
	{
		f = f1(hash[B], hash[C], hash[D]);
		g = i;
	}
	else if (i < 32)
	{
		f = f2(hash[B], hash[C], hash[D]);
		g = (i * 5 + 1) % 16;
	}
	else if (i < 48)
	{
		f = f3(hash[B], hash[C], hash[D]);
		g = (i * 3 + 5) % 16;
	}
	else
	{
		f = f4(hash[B], hash[C], hash[D]);
		g = (7 * i) % 16;
	}
	f = f + hash[A] + g_k[i] + m[g];
	hash[A] = hash[D];
	hash[D] = hash[C];
	hash[C] = hash[B];
	hash[B] = hash[B] + rotate_left(f, g_s[i]);
}
