/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 15:19:27 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/31 15:19:29 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		free_buf(t_buf *buf)
{
	free(buf->buf);
	free(buf->hash);
	ft_bzero(buf, sizeof(t_buf));
}

void		fatal_err(char *mes)
{
	if (mes)
		ft_putendl_fd(mes, STDERR_FILENO);
	exit(1);
}

void		*xmalloc(size_t n)
{
	void *ret;

	if (!(ret = malloc(n)))
	{
		fatal_err("malloc returned null");
		exit(1);
	}
	return (ft_memset(ret, 0, n));
}

uint32_t	*swap_bytes_order(uint32_t *bytes, size_t size)
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
