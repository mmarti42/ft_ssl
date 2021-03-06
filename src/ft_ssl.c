/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:35:35 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/31 15:35:36 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	readall(int fd, t_buf *ssl)
{
	int rr;
	int block;

	block = SBLOCK;
	ssl->memsize = SBLOCK;
	if (!(ssl->buf = (uint8_t *)malloc(ssl->memsize)))
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

void	hsopt(char **av, t_buf *buf)
{
	if (!av[1])
		fatal_err("option s requires argument");
	if (!(buf->buf = (uint8_t *)ft_strdup(av[1])))
		fatal_err(strerror(errno));
	buf->siz = ft_strlen((char *)buf->buf);
	buf->memsize = buf->siz + 1;
	g_opt.string = true;
}

char	**hopts(char **av, t_buf *buf, t_bool *stdinput)
{
	char opt;

	opt = *(*av + 1);
	if (opt == 'p')
	{
		g_opt.p = true;
		*stdinput = false;
		readall(STDIN_FILENO, buf);
		write(STDOUT_FILENO, buf->buf, buf->siz);
	}
	else if (opt == 's')
	{
		hsopt(av, buf);
		buf->argument = av[1];
		*stdinput = false;
		return (av + 2);
	}
	else if (opt == 'r')
		g_opt.reverse_print = 1;
	else if (opt == 'q')
		g_opt.quiet_mode = 1;
	else
		fatal_err("usage: ft_ssl command [-pqrs] [command args]");
	return (++av);
}

void	set_hash_func(char *av, t_hash_func *f)
{
	if (!ft_strcmp(av, "md5"))
		*f = md5;
	else if (!ft_strcmp(av, "sha256"))
		*f = sha256;
	else
		fatal_err("ft_ssl: Error: invalid\
command\nMessage digest commands:\nmd5\nsha256");
}

int		main(int ac, char **av)
{
	t_hash_func f;

	(void)ac;
	if (!av[1])
		fatal_err("usage: ft_ssl command [-pqrs] [command args]");
	set_hash_func(av[1], &f);
	hash_start(av + 2, f);
	return (0);
}
