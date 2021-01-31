/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:24:03 by mmarti            #+#    #+#             */
/*   Updated: 2021/01/25 18:24:05 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include "libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <errno.h>

# define SBLOCK 1024
# define A 0
# define B 1
# define C 2
# define D 3
# define E 4
# define F 5
# define G 6
# define H 7

typedef struct	s_fl
{
	t_bool		reverse_print;
	t_bool		quiet_mode;
	t_bool		string;
	t_bool		p;
}				t_fl;

typedef struct	s_buf
{
	const char	*name;
	const char	*argument;
	int8_t		hash_size;
	uint32_t	*hash;
	uint8_t		*buf;
	size_t		siz;
	size_t		memsize;
}				t_buf;

typedef uint32_t *(*t_hash_func)(t_buf *data);

t_fl			g_opt;

/*
** utils.c
*/
void			*xmalloc(size_t n);
void			free_buf(t_buf *buf);
void			fatal_err(char *mes);
uint32_t		b_swap32(uint32_t x);
uint64_t		b_swap64(uint64_t x);
uint32_t		*swap_bytes_order(uint32_t *bytes, size_t size);
uint32_t		rotate_left(uint32_t num, int n);
uint32_t		rotate_right(uint32_t num, int n);
void			append_byte(t_buf *data, uint8_t byte);

uint32_t		*md5(t_buf *data);
void			md5setfg(uint32_t *f, uint32_t *g, int i, uint32_t *hash);

void			hash_start(char **av, t_hash_func f);
void			align(t_buf *data);

uint32_t		*sha256(t_buf *data);

void			readall(int fd, t_buf *ssl);
char			**hopts(char **av, t_buf *buf, t_bool *stdinput);

#endif
