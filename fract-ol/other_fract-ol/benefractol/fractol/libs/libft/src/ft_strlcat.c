/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blucken <blucken@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 01/10/2024 17:39:32 by blucken           #+#    #+#             */
/*   Updated: 01/10/2024 17:39:32 by blucken          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t dstsize)
{
	size_t	dst_len;
	size_t	index;
	size_t	i;

	dst_len = ft_strlen(d);
	index = 0;
	while (d[index])
		index++;
	i = 0;
	while (s[i] && (i + index + 1) < (dstsize))
	{
		d[index + i] = s[i];
		i++;
	}
	if (i < dstsize)
		d[index + i] = '\0';
	if (dstsize <= dst_len)
		return (ft_strlen(s) + dstsize);
	else
		return (ft_strlen(s) + dst_len);
}
