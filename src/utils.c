#include "ft_ssl.h"

uint32_t	rotate_right(uint32_t num, int n)
{
	return (num >> n) | (num << (32 - n));
}

uint32_t	rotate_left(uint32_t num, int n)
{
	return (num << n) | (num >> (32 - n));
}

void	fatal_err(char *mes) 
{
	if (mes)
		ft_putendl_fd(mes, STDERR_FILENO);
	exit(1);
}

void	*xmalloc(size_t n)
{
	void *ret;

	if (!(ret = malloc(n)))
	{
		fatal_err("malloc returned null");
		exit(1);
	}
	return (ft_memset(ret, 0, n));
}

uint32_t b_swap32(uint32_t x)
{
	return ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >> 8)
	| (((x) & 0x0000ff00u) << 8) | (((x) & 0x000000ffu) << 24));
}

uint32_t *swap_bytes_order(uint32_t *bytes, size_t size)
{
	uint32_t *ret;

	ret = bytes;
	while (size--)
	{
		*bytes = b_swap32(*bytes);
		bytes++;
	}
	return (ret);
}

void	append_byte(t_buf *data, uint8_t byte)
{
	if (data->siz == data->memsize)
		data->buf = realloc(data->buf, data->memsize += SBLOCK);
	data->buf[data->siz] = byte;
	(data->siz)++;
}

void	free_buf(t_buf *buf)
{
	free(buf->buf);
	free(buf->hash);
	ft_bzero(buf, sizeof(t_buf));
}