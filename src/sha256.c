#include "ft_ssl.h"
#include "sha256.h"

void sha256_init(uint32_t *h)
{
    h[0] = 0x6a09e667;
    h[1] = 0xbb67ae85;
    h[2] = 0x3c6ef372;
    h[3] = 0xa54ff53a;
    h[4] = 0x510e527f;
    h[5] = 0x9b05688c;
    h[6] = 0x1f83d9ab;
    h[7] = 0x5be0cd19;
}

void    generate_w(uint32_t w[64], uint32_t *buf)
{
    int i;
    uint32_t s1;
    uint32_t s0;

    i = 16;
    ft_bzero(w, 64);
    ft_memcpy(w, buf, sizeof(uint32_t) * 16);
    swap_bytes_order(w, 16);
    while (i < 64)
    {
        s0 = rotate_right(w[i - 15], 7) ^ rotate_right(w[i - 15], 18) ^ (w[i - 15] >> 3);
        s1 = rotate_right(w[i - 2], 17) ^ rotate_right(w[i - 2], 19) ^ (w[i - 2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
        i++;
    }
}

void    sha256step(uint32_t* w, uint32_t *v, int i)
{
    uint32_t s0;
    uint32_t s1;
    uint32_t ch;
    uint32_t temp1;
    uint32_t temp2;
    uint32_t maj;

    s1 = rotate_right(v[E], 6) ^ rotate_right(v[E], 11) ^ rotate_right(v[E], 25);
    ch = (v[E] & v[F]) ^ ((~v[E]) & v[G]);
    temp1 = v[H] + s1 + ch + k[i] + w[i];
    s0 = rotate_right(v[A], 2) ^ rotate_right(v[A], 13) ^ rotate_right(v[A], 22);
    maj = (v[A] & v[B]) ^ (v[A] & v[C]) ^ (v[B] & v[C]);
    temp2 = s0 + maj;

    v[H] = v[G];
    v[G] = v[F];
    v[F] = v[E];
    v[E] = v[D] + temp1;
    v[D] = v[C];
    v[C] = v[B];
    v[B] = v[A];
    v[A] = temp1 + temp2;
}

void	sha256prepare(t_buf *data)
{
	uint64_t bitlen;
	
    data->name = "SHA256";
	bitlen = data->siz * 8;
	align(data);
	*(uint64_t *)(data->buf + data->siz) = b_swap64(bitlen);
	data->siz += 8;
}

uint32_t *sha256(t_buf *data)
{
    uint32_t    w[64];
    size_t      ct;
    int         i;
    uint32_t    v[8];

    ct = 0;
    sha256prepare(data);
    data->hash = (uint32_t *)xmalloc((data->hash_size = 8) * sizeof(uint32_t));
    sha256_init(data->hash);
    while (ct < data->siz)
    {
        i = -1;
        ft_memcpy(v, data->hash, sizeof(uint32_t) * data->hash_size);
        generate_w(w, (uint32_t *)(data->buf + ct));
        while (++i < 64)
            sha256step(w, v, i);
        ct += 64;
        data->hash[0] += v[A];
        data->hash[1] += v[B];
        data->hash[2] += v[C];
        data->hash[3] += v[D];
        data->hash[4] += v[E];
        data->hash[5] += v[F];
        data->hash[6] += v[G];
        data->hash[7] += v[H];
    }
    return data->hash;//swap_bytes_order(data->hash, data->hash_size);
}