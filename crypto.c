//
// Created by bouch on 10/09/15.
//

#include "crypto.h"
#include "strings.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

char shift_char(char s, int n)
{
    char final;
    if (isalpha(s))
    {
        final = (tolower(s) + n) % 'a' + 'a';
    }
    else
    {
        final = s;
    }
}

char *shift(char *s, int n)
{
    int len_s = length(s);
    char *string = malloc(sizeof(char) * (len_s + 1));
    for (int i = 0; i < len_s; i++)
    {
        string[i] = shift_char(s[i], n);
    }

    return string;
}

char **init_dict()
{
    FILE *dict = fopen("/home/bouch/ClionProjects/C/dict.txt", "r");
    char **strings = malloc(sizeof(char *));
    int len_strings = 0;

    strings[len_strings] = malloc(sizeof(char) * 30);
    fscanf(dict, "%s", strings[len_strings++]);

    while (1)
    {
        strings = realloc(strings, sizeof(char *) * (len_strings + 1));
        strings[len_strings] = malloc(sizeof(char) * 30);
        fscanf(dict, "%s", strings[len_strings++]);
        printf("%s, %d\n", strings[len_strings - 1], len_strings);

        if (strings[len_strings - 1][0] == '\0')
        {
            strings[len_strings - 1] = NULL;
            break;
        }
    }

    return strings;
}

//change to better search
int is_word(char *s)
{
    char **list = init_dict();
    if (!s || length(s) == 0)
    {
        return 0;
    }

    int index = 0;
    while (list[index][0] != s[0])
    {
        index++;
    }

    while (strcmp_ign_case(list[index], s) != 0 && list[index] != NULL)
    {
        index++;
    }

    if (list[index])
    {
        return 1;
    }
    return 0;
}