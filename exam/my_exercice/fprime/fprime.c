#include <unistd.h>
#include <stdlib.h>
int	prime_put(int prime)
{
	char	c;

	if (prime >= 10)
	{
		prime_put(prime / 10);
		prime_put(prime % 10);
	}
	else
	{
		c =  prime % 10 + '0';
		write(1, &c, 1);
	}
	return (1);
}	

int	prime_check(int nb)
{
	int	i;

	i = 2;
	while (nb % i != 0)
		i++;
	if (i == nb)
		return (1);
	return (0);
}

int	prime_next(void)
{
	static int	prime;
	
	if (prime == 0)
		prime = 1;
	prime++;
	while (!prime_check(prime))
		prime++;
	return (prime);
}

int	main(int ac, char **av)
{
	int	nb;
	int	prime;
	int	wrote;

	if (ac != 2)
		return (write(1, "\n", 1));
	nb = atoi(av[1]);
	if (nb == 1)
		return (write(1, "1\n", 2));
	if (prime_check(nb))
		return(prime_put(nb), write(1, "\n", 1));
	wrote = 0;
	while (nb > 1)
	{
		prime = prime_next();
		while (nb % prime == 0)
		{
			if (wrote == 1)
				write(1, "*", 1);
			wrote = prime_put(prime);
			nb = nb / prime;
		}
	}
	return (write(1, "\n", 1));
}

