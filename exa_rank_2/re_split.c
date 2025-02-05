#include <stdlib.h>
#include <stdio.h>

int word_count(char *str);
int word_len(char *str);

char **ft_split(char *str)
{
    char **new;
    int i = 0, a = 0, b = 0;

    if (str == NULL)
        return NULL;

    new = malloc(sizeof(char *) * (word_count(str) + 1)); // Correction: sizeof(char *) au lieu de sizeof(char)
    if (!new)
        return NULL;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;
        if (str[i] != '\0') // Correction: vérifier si str[i] n'est pas '\0'
        {
            new[a] = malloc(sizeof(char) * (word_len(&str[i]) + 1));
            if (!new[a])
                return NULL;
            while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
            {
                new[a][b] = str[i];
                b++;
                i++;
            }
            new[a][b] = '\0';
            b = 0;
            a++;
        }
    }
    new[a] = NULL;
    return new;
}

int word_count(char *str)
{
    int count = 0;

    while (*str)
    {
        while (*str == ' ' || *str == '\t' || *str == '\n')
            str++;
        if (*str != '\0')
        {
            count++;
            while (*str != ' ' && *str != '\t' && *str != '\n' && *str)
                str++;
        }
    }
    return count;
}

int word_len(char *str)
{
    int len = 0;

    while (*str != ' ' && *str != '\t' && *str != '\n' && *str)
    {
        len++;
        str++;
    }
    return len;
}

int main(void)
{
    char **new;
    char str[] = "t a b c ";
    int i = 0;

    new = ft_split(str);
    while (new[i])
    {
        printf("%s\n", new[i]);
        i++;
    }

    // Free allocated memory
    i = 0;
    while (new[i])
    {
        free(new[i]);
        i++;
    }
    free(new);

    return 0;
}