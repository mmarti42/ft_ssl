#include "ft_ssl.h"

void readall(int fd, t_buf *ssl)
{
	int rr;
	int block = SBLOCK;

	if (!(ssl->buf = (uint8_t *)malloc(ssl->memsize = SBLOCK)))
		exit(1);
	while ((rr = read(fd, ssl->buf + ssl->siz, block)))
	{
		if (rr < 0)
			fatal_err(strerror(errno));
		if (block - rr <= 0)
		{
			ssl->buf = realloc(ssl->buf, ssl->memsize += SBLOCK);
			block = SBLOCK;
		}
		else
			block -= rr;
		ssl->siz += rr;
	}
}

char	**hopts(char **av, t_buf *buf)
{
	char opt = *(*av + 1);

	if (opt == 'p')
	{
		readall(STDIN_FILENO, buf);
		write(STDOUT_FILENO, buf->buf, buf->siz);
	}
	else if (opt == 's')
	{
		if (!av[1])
			fatal_err("option s requires argument");
		if (!(buf->buf = (uint8_t *)ft_strdup(av[1])))
			fatal_err(strerror(errno));
		buf->siz = ft_strlen((char *)buf->buf);
		buf->memsize = buf->siz + 1;
		return av + 2;
	}
	else if (opt == 'r')
		g_opt.reverse_print = 1;
	else if (opt == 'q')
		g_opt.quiet_mode = 1;
	else
		fatal_err("invalid_option\nusage: ft_ssl command [-pqrs] [command args]");
	return ++av;
}

void	set_hash_func(char *av, t_hash_func *f)
{
	if (!ft_strcmp(av, "md5"))
		*f = md5;
	// else if (!ft_strcmp(av, "sha256"))
	// 	hash_func = sha256_hash;
	else
	{
		//ft_printf("%s%s\n%s\n", "ft_ssl: Error: ", av[1], " is an invalid command"\
		//"Message digest commands:\n md5\n");
		fatal_err("ft_ssl: Error: invalid command\nMessage digest commands:\n md5\nsha256");
	}
}

int main(int ac, char **av) 
{
	t_hash_func f;

	(void)ac;
    if (!av[1])
		fatal_err("usage: ft_ssl command [-pqrs] [command args]");
	set_hash_func(av[1], &f);
	hash_start(av + 2, f);
	return (0);
}
