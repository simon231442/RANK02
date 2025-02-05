/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_amplify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 14:35:44 by srenaud           #+#    #+#             */
/*   Updated: 2025/01/14 15:25:53 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_amplify(char *str)
{
	int	i;
	int	repeat_acc;

	i = 0;
	repeat_acc = 1;
	while (*str)
	{
		if (*str == ' ')
			write(1, str, 1);
		else
		{
			while (i < repeat_acc)
			{
				write(1, str,1);
				i++;
			}
			i = 0;
			repeat_acc++;
		}
		str++;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		write(1, "\n", 1);
	else
		alpha_amplify(av[1]);
	return (0);
}

