/* бич-варинат, переделать */

#include "libft.h"

t_list *ft_lstins(t_list *first, void *data)
{
    t_list *new;
    t_list *ret = first;

    if (!data)
        return first;
    new = (t_list *)ft_xmalloc(sizeof(t_list));
    new->data = data;
    if (!first)
        return new;
    while (first->next)
        first = first->next;
    first->next = new;
    new->prev = first;
    return ret;
}