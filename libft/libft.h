/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:41:30 by mmarti            #+#    #+#             */
/*   Updated: 2019/05/16 16:05:10 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define DELDATA 1
# define NDELDATA 0

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef	struct		s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void				ft_bzero(void *destination, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
void				*ft_memcpy(void *destination,
		const void *source, size_t n);
void				*ft_memmove(void *destination,
		const void *source, size_t n);
void				*ft_memset(void *destination, int c, size_t n);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				ft_putchar(char c);
void				ft_putstr(char const *c);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strchr(const char *str, int ch);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strcpy(char *destination, const char *source);
char				*ft_strdup(const char *str);
size_t				ft_strlen(const char *string);
char				*ft_strnchr(const char *str, int ch, size_t n);
int					ft_strncmp(char const *s1,
		char const *s2, size_t n);
char				*ft_strncpy(char *dest,
		const char *src, size_t n);
char				*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strstr(char const *haystack, char const *needle);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *str1, const void *str2, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s1, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl(char const *s);
void				*ft_memalloc(size_t size);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
size_t				ft_strnlen(char const *str, int n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_skip_whitespaces(char const *s);
char				*ft_strtrim(char const *s);
void				ft_putnbr(int nb);
size_t				ft_dcount(int nb);
char				*ft_itoa(int n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				**ft_strsplit(char *s, int c);
size_t				ft_strlenbr(const char *s);
int					ft_pow2(int pow);
char				*ft_tobin(int num);
char				*ft_strrev(char *s);
int					ft_maxlog2(int num);
int					ft_sqrt(int nb);
size_t				ft_strwlen(char *s);
char				*ft_insert(char *str, char *todel, char *toins);
size_t				ft_count_str(char **tab);
size_t				ft_strclen(char *s, char c);
char				**ft_strtok(char *s);
void				*ft_xmalloc(size_t size);
char				*parse_opt(char const **av, char const *opt_list, char *buf);
t_list				*ft_lstins(t_list *first, void *data);
void				ft_lstdel(t_list *l, char flag);
char				*s_parse_opt(char const *av, char const *opt_list, char *buf);

#endif
