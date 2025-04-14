/* ************************************************************************** */
/*   .         '            .                                                 */
/*        *          .       .     '           +           .        '         */
/*       .       *       '                .     .      .       +         .    */
/*   .      *                *      +                              .          */
/*         .                .                 .                         '     */
/*    '            '    .         .     '             +      *                */
/*     .          42, vers le cursus et au-dela         .   * *    .      '   */
/*               .                                '        *   *              */
/* *   '*             +      '    .                       * * * *      .      */
/*         *                .              .             *       *          . */
/*              *                       '       .       * *     * *    '      */
/*   .                  *      '   .                   *   *   *   *     '    */
/*      .      *             .            .           * * * * * * * *      .  */
/*                    *            .    .            *               *   .    */
/*                                                  * *             * *       */
/*   filter.c                                      *   *           *   *      */
/*                                                * * * *         * * * *     */
/*   By: srenaud <srenaud@student.42lausanne.ch> *       *       *       *    */
/*                                              * *     * *     * *     * *   */
/*   Created: 2025/04/14 14:44:09 by srenaud   *   *   *   *   *   *   *   *  */
/*   Updated: 2025/04/14 14:44:09 by srenaud  * * * * * * * * * * * * * * * * */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#define BUFF_SIZE 1024

static int	ft_strcmp(char *buff, char *s)
{
	int	i;

	i = 0;
	while (buff[i] && s[i])
	{
//printf("\n%dnca compar coco\n",i);
		if (buff[i] != s[i])
			return(0);
		i++;
	}
	return (1);
}

static void	filter(char *buff, char *s)
{
	int	i;
	size_t	b;

	i = 0;
	b = 0;
	while (buff[i])
	{
		if (ft_strcmp(&buff[i], s))
		{
//printf("\nvalide\n");
			while (b++ < strlen(s))
			{
				write(1, "*", 1);
				i++;
			}
			b = 0;
		}
		else
			write(1, &buff[i++], 1);
	}
}




int	main(int ac, char **av)
{
	char	buff[BUFF_SIZE + 1];
	int		bytes_read;

	if (ac != 2)
		return (1);
	while (1)
	{
		bytes_read = read(0, buff, BUFF_SIZE);
		if (bytes_read > 0)
			filter(buff, av[1]);
		else if (bytes_read == 0)
			return (1);
		else
			return (write(2, "Error: ", 7));
	}
	return (0);
}
