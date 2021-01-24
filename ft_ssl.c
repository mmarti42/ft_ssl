#include <ft_ssl.h>

void	fatal_err(char *mes) {
	ft_putendl_fd(mes, STDERR_FILENO);
	exit(1);
}

int handle_op(char **av, int *i, t_fl *flags)
{
	char *buf;
	char c = *(av[*i]);
	if (c == 'r')
		flags->reverse_print = 1;
	else if (c == 'q')
		flags->quiet_mode = 1;
	else if (c == 's')
	{
		if (*(av[*i] + 1) == 0)
		{
			phash_md5(av[*i + 1]);
			*i += 2;
		}
		else
		{
			phash_md5(av[*i] + 1);
			*i++;
		}
		return 0;
	}
	else if (c == 'p')
	{
		ft_putendl(buf = readall(STDIN_FILENO));
		phash_md5(buf);
		free(buf);
	}
	return (1);
}


void	md5(char **av)
{
	int i = 0;
	t_fl flags;

	ft_bzero(&flags, sizeof(flags));
	if (!*av)
		phash(readall(STDIN_FILENO));
	while (av[i][0] == '-')
	{
		while (handle_op(av, &i, &flags))
			(av[i])++;
	}
}

int main(int ac, char **av) 
{
    if (!av[1])
		fatal_err("usage: ft_ssl command [-pqrs] [command args]");
	if (!ft_strcmp(av[1], "md5"))
		ft_md5(av + 2);
}