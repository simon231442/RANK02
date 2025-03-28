/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h  	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelma <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:39:27 by manuelma          #+#    #+#             */
/*   Updated: 2024/10/24 19:44:23 by manuelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_strlen_printf(char *str);
int	printchar(int c);
int	printstr(char *str);
int	printptr(void *ptr);
int	recursive_print(unsigned long long int nbr, char *base);
int	ft_putnbr_base(long long int nbr, char *base);
int	ft_printf(const char *format, ...);

#endif
