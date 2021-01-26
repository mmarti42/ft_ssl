#include "ft_ssl.h"

//t_md5hash md5(t_buf *data);

void	fatal_err(char *mes) 
{
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

void	append_byte(t_buf *data, uint8_t byte)
{
	if (data->siz == data->memsize)
		data->buf = realloc(data->buf, data->memsize += SBLOCK);
	data->buf[data->siz] = byte;
	(data->siz)++;
}

void	align(t_buf *data)
{
	append_byte(data, 128);

	while (data->siz % 64 != 56)
		append_byte(data, 0);
}

uint32_t	rotate_left(uint32_t num, int n)
{
	return (num << n) | (num >> (32 - n));
}

void md5_init(t_md5hash *a, t_md5hash *v)
{
	v->a = 0x67452301;
	v->b = 0xEFCDAB89;
	v->c = 0x98BADCFE;
	v->d = 0x10325476;
	ft_memcpy(a, v, sizeof(t_md5hash));
}

void	md5_hash(uint32_t *m, t_md5hash *v, int i)
{
	uint32_t g, f;

	if (i < 16)
	{
		f = f1(v->b, v->c, v->d);
		g = i;
	}
	else if (i < 32)
	{
		f = f2(v->b, v->c, v->d);
		g = (i * 5 + 1) % 16;
	}
	else if (i < 48)
	{
		f = f3(v->b, v->c, v->d);
		g = (i * 3 + 5) % 16;
	}
	else
	{
		f = f4(v->b, v->c, v->d);
		g = (7 * i) % 16;
	}
	f = f + v->a + k[i] + m[g];
	v->a = v->d;
	v->d = v->c;
	v->c = v->b;
	v->b = v->b + rotate_left(f, s[i]);
}

// t_md5hash md5(t_buf *data)
// {
// 	t_md5hash v;
// 	t_md5hash saved;
// 	uint64_t bitlen = data->siz * 8;
// 	size_t	ct = 0;
// 	int i;

// 	align(data);
// 	*(uint64_t *)(data->buf + data->siz) = bitlen;
// 	data->siz += 8;
// 	md5_init(&saved, &v);
// 	// while (ct < data->siz)
// 	// {
// 		i = 0;
// 		v.a = saved.a;
// 		v.b = saved.b;
// 		v.c = saved.c;
// 		v.d = saved.d;
// 		while (i < 64)
// 		{
// 			md5_hash((uint32_t *)(data->buf + ct), &v, i);
// 			i++;
// 		}
// 		saved.a += v.a;
// 		saved.b += v.b;
// 		saved.c += v.c;
// 		saved.d += v.d;
// 		ct += 64;
// //	}
// 	return saved;
// }

uint32_t b_swap32(uint32_t x)
{
	return ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >> 8)
	| (((x) & 0x0000ff00u) << 8) | (((x) & 0x000000ffu) << 24));
}

void print_md5hash(t_md5hash hash)
{
	ft_printf("%08x%08x%08x%08x\n", b_swap32(hash.a), b_swap32(hash.b), b_swap32(hash.c), b_swap32(hash.d));
}

void	phash(char *algo, t_buf *data)
{
	char *hash;

	if (!ft_strcmp(algo, "md5"))
		print_md5hash(md5(data));
}

t_buf *readall(int fd)
{
	t_buf *ret;
	int block = SBLOCK;
	ret->memsize = 1024;
	int rr;

	ret = (t_buf *)xmalloc(sizeof(t_buf));
	ret->buf = (uint8_t*)xmalloc(ret->memsize);
	uint8_t* buf = ret->buf;
	while ((rr = read(fd, buf, block)))
	{
		if (rr < 0)
			fatal_err(strerror(errno));
		if (rr == block)
			ret->buf = realloc(ret->buf, ret->memsize += block);
		ret->siz += rr;
		buf = ret->buf + ret->siz;
	}
	return ret;
}

void	free_buf(t_buf **buf)
{
	if (*buf)
	{
		free((*buf)->buf);
		free(*buf);
		*buf = NULL;
	}
}

void	handle_op(int ac, char **av)
{
	t_buf *buf = NULL;
	int fd;
	int i;

	i = 0;
	if (!av[1])
		phash(*av, buf = readall(STDIN_FILENO));
	else
	{
		while (av[++i] && *(av[i]) == '-')
		{
			if (*(av[i] + 1) == 'p')
			{
				buf = readall(STDIN_FILENO);
				write(STDOUT_FILENO, buf->buf, buf->siz);
				phash(*av, buf);
			}
			else if (*(av[i] + 1) == 's')
			{
				if (!(av[++i]))
					fatal_err("option i requires argument");
				buf = (t_buf *)xmalloc(sizeof(t_buf));
				buf->buf = (uint8_t *)ft_strdup(av[i]);
				buf->siz = ft_strlen(av[i]);
				buf->memsize = buf->siz + 1;
				phash(*av, buf);
			}
			else if (*(av[i] + 1) == 'q')
				g_opt.quiet_mode = 1;
			else if (*(av[i] + 1) == 'r')
				g_opt.reverse_print = 1;
			else
				fatal_err("invalid option");
			if (buf)
				free_buf(&buf);
		}
	}
	while (av[i])
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
			fatal_err(strerror(errno));
		phash(*av, buf = readall(fd));
		write(STDOUT_FILENO, buf->buf, buf->siz);
		free_buf(&buf);
		close(fd);
		i++;
	}
}

t_bool in_list(char **list, char *s)
{
	while (*list)
	{
		if (!ft_strcmp(s, *list))
			return true;
	}
	return false;
}

t_md5hash md5(t_buf *data)
{
	t_md5hash v;
	t_md5hash saved;
	uint64_t bitlen = data->siz * 8;
	size_t	ct = 0;
	int i;

	align(data);
	*(uint64_t *)(data->buf + data->siz) = bitlen;
	data->siz += 8;
	md5_init(&saved, &v);
	while (ct < data->siz)
	 {
		i = 0;
		v.a = saved.a;
		v.b = saved.b;
		v.c = saved.c;
		v.d = saved.d;
		while (i < 64)
		{
			md5_hash((uint32_t *)(data->buf + ct), &v, i);
			i++;
		}
		saved.a += v.a;
		saved.b += v.b;
		saved.c += v.c;
		saved.d += v.d;
		ct += 64;
	}
	return saved;
}

int main(int ac, char **av) 
{
    if (!av[1])
		fatal_err("usage: ft_ssl command [-pqrs] [command args]");
	if (!ft_strcmp(av[1], "md5"))
		md5(ac - 1, av + 1)
	else
	{
		ft_printf("%s%s\n%s\n", "ft_ssl: Error: ", av[1], " is an invalid command"\
		"Message digest commands:\n md5\n");
	}
	handle_op(ac -1, av + 1);
	return (0);
}
