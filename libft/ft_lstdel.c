#include "libft.h"

void	ft_lstdel(t_list *l, char flag)
{
	t_list *tmp;

	if (flag == DELDATA)
	{
		while (l)
		{
			tmp = l;
			l = l->next;
			free(tmp->data);
			free(tmp);
		}
	}
	else
	{
		while (l)
		{
			tmp = l;
			l = l->next;
			free(tmp);
		}
	}
}
