
#include <stdlib.h>

int	count_word(char *str);
int	sp_word_len(char *str);

char	**ft_split(char *str)
{
	char	**new;
	int	word_len;


	new = malloc(sizeof(char)*(count_word(str) + 1));
	if (!new)
		return (NULL);

	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str != ' ' || *str != '\t' || *str != '\n' || *str)
		{
			word_len = sp_word_len(str);
			*new = malloc(sizeof(char) * (word_len + 1));
			//if (!*new)
				//free return NULL
			while(*str != ' ' || *str != '\t' || *str != '\n' || *str)
			{
				*(*new) = *str;
				(*new)++;
				str++;
			}
			*(*new) = '\0'
		}
	}
	return (new);
}

int	count_word(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		if (*str != ' ' || *str != '\t' || *str != '\n' || *str)
		{
			count++;
			str++;
		}
		while (*str != ' ' || *str != '\t' || *str != '\n' || *str)
			str++;
	}
	return (count);
}

int	sp_word_len(char *str)
{
	int	len;

	len = 0;
	while (*str != ' ' || *str != '\t' || *str != '\n' || *str)
	{        
	       	str++;
		len++;
	}
	return (len);
}


#include<stdio.h>

int	main(void)
{
	char	str[] = "hello la famille,	ca\n   comment";

	char	**new;
	new = ft_split(str);

	while(*new)
	{
		printf("%s\n",*new);
		new++;
	}
	return (0);
}


