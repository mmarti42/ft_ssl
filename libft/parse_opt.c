#include "libft.h"

/*
** buf должен быть не менее strlen(opt_list) + 1
** При ошибке возвращает NULL
** s_parse_opt принимает строку без '-', т.e. *(av + 1)!!
*/

static int get_opt(char const *av, char const *opt_list, char *buf)
{
    while (*++av)
    {
        if (!ft_strchr(opt_list, *av))
            return (-1);
        if (!ft_strchr(buf, *av))
            buf[ft_strlen(buf)] = *av;
    }
    return (0);
}

char	*parse_opt(char const **av, char const *opt_list, char *buf)
{
    ft_bzero(buf, ft_strlen(opt_list) + 1);
    while (*av)
    {
        if (**av == '-' && ft_isalpha(*(*av + 1)))
        {
            if (get_opt(*av, opt_list, buf) < 0)
                return NULL;
        }
        av++;
    }
    return buf;
}

char	*s_parse_opt(char const *av, char const *opt_list, char *buf)
{
    ft_bzero(buf, ft_strlen(opt_list) + 1);
    while (*av)
    {
        if (!ft_strchr(opt_list, *av))
            return (NULL);
        if (!ft_strchr(buf, *av))
			buf[ft_strlen(buf)] = *av;
		av++;
    }
    return (buf);
}