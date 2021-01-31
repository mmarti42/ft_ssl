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

void	print_arg(const char *argument, const char *name)
{
	if (g_opt.reverse_print == false && argument)
	{
		if (g_opt.string)
			ft_printf("%s(\"%s\")= ", name, argument);
		else
			ft_printf("%s(%s)= ", name, argument);
	}
	else if (argument)
	{
		if (g_opt.string)
			ft_printf(" \"%s\"", argument);
		else
			ft_printf(" %s", argument);
	}
}

void	print_hash(t_buf *data)
{
	size_t		size;
	uint32_t	*hash;

	size = data->hash_size;
	hash = data->hash;
	if (g_opt.quiet_mode == false && g_opt.reverse_print == false)
		print_arg(data->argument, data->name);
	while (size--)
	{
		ft_printf("%08x", *hash);
		hash++;
	}
	if (g_opt.quiet_mode == false && g_opt.reverse_print == true)
		print_arg(data->argument, data->name);
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
		buf->argument = *av;
		f(buf);
		print_hash(buf);
		free_buf(buf);
		av++;
	}
}

void	from_console(t_buf *buf, t_hash_func f)
{
	readall(STDIN_FILENO, buf);
	f(buf);
	print_hash(buf);
	free_buf(buf);
}

void	hash_start(char **av, t_hash_func f)
{
	t_buf	buf;
	t_bool	stdinput;

	stdinput = true;
	ft_bzero(&buf, sizeof(buf));
	while (*av)
	{
		if (**av != '-')
		{
			stdinput = false;
			break ;
		}
		av = hopts(av, &buf, &stdinput);
		if (buf.memsize)
		{
			f(&buf);
			print_hash(&buf);
			free_buf(&buf);
		}
	}
	if (stdinput)
		return (from_console(&buf, f));
	hash_file(av, &buf, f);
}
