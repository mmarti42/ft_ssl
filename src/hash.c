/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:28:52 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/31 15:28:53 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	align(t_buf *data)
{
	append_byte(data, 128);
	while (data->siz % 64 != 56)
		append_byte(data, 0);
}

void	print_hash(uint32_t *hash, uint8_t size, const char *name)
{
	ft_printf("%s= ", name);
	while (size--)
	{
		ft_printf("%08x", *hash);
		hash++;
	}
	ft_printf("\n");
}

void	hash_file(char **av, t_buf *buf, t_hash_func f)
{
	int fd;

	while (*av)
	{
		if ((fd = open(*av, O_RDONLY)) < 0)
			fatal_err(strerror(errno));
		readall(fd, buf);
		close(fd);
		print_hash(f(buf), buf->hash_size, buf->name);
		free_buf(buf);
		av++;
	}
}

void	hash_start(char **av, t_hash_func f)
{
	t_buf	buf;

	ft_bzero(&buf, sizeof(buf));
	if (!*av)
	{
		readall(STDIN_FILENO, &buf);
		print_hash(f(&buf), buf.hash_size, buf.name);
		free_buf(&buf);
		return ;
	}
	while (*av)
	{
		if (**av != '-')
			break ;
		av = hopts(av, &buf);
		if (buf.siz)
		{
			print_hash(f(&buf), buf.hash_size, buf.name);
			free_buf(&buf);
		}
	}
	hash_file(av, &buf, f);
}
