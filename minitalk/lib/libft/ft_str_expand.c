/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srenaud <srenaud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:03:50 by srenaud           #+#    #+#             */
/*   Updated: 2025/04/01 16:03:50 by srenaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_expand(char *str, size_t new_size)
{
	char	*str_new;
	size_t	i;

	str_new = ft_calloc(sizeof(char), new_size + 1);
	if (!str_new)
	{
		if (str)
			free(str);
		return (NULL);
	}
	if (!str)
		return (str_new);
	i = 0;
	while (str[i] && i < new_size)
	{
		str_new[i] = str[i];
		i++;
	}
	free(str);
	return (str_new);
}
