#include "libft.h"

void    *ft_xmalloc(size_t size)
{
    void *ret;

    if (!(ret = malloc(size)))
    {
        dprintf(STDERR_FILENO, "libft: malloc: %s\n", strerror(errno));
        exit(1);
    }
    return memset(ret, 0, size);
}