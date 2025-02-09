
#include <unistd.h>

void	rev_wstr(char *str)
{
	int	i;
	int	b;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		if (str[i] == ' '/* || str[i] == '\t'*/)
			i--;
		else
		{
			b = 0;
			while (str[i] != ' '/* && str[i] != '\t'*/ && i >= 0)
			{
				b++;
				i--;
			}
			write(1, &str[i + 1], b);
			if (i >= 0)
				write(1, " ", 1);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		rev_wstr(av[1]);
		write(1, "\n", 1);
		return (0);
	}
}

