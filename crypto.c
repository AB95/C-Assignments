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
        final = tolower(s) + n;
        if (!isalpha(final))
        {
            final -= 26;
        }
    }
    else
    {
        final = s;
    }
    return final;
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

    char c;
    int lengt = 0;
    while ((c = getc(dict)) != EOF)
    {
        if (c == '\n')
        {
            lengt++;
        }
    }
    fseek(dict, 0, SEEK_SET);

    char **strings = malloc(sizeof(char *) * lengt);
    int len_strings = 0;

    for (int i = 0; i < lengt; i++)
    {
        strings[i] = malloc(sizeof(char) * 30);
    }

    while (len_strings <= lengt)
    {
        fscanf(dict, "%s", strings[len_strings++]);
    }
    strings[--len_strings] = NULL;
    fclose(dict);

    return strings;
}

char **init_file(int n)
{
    FILE *file = fopen("/home/bouch/ClionProjects/C/jaws_encr.txt", "r");

    char c;
    int words = 0;

    char **strings = malloc(sizeof(char *) * n);

    for (int i = 0; i < n; i++)
    {
        strings[i] = malloc(sizeof(char) * 30);
    }

    int letter;
    while (words < n)
    {
        fscanf(file, "%s", strings[words++]);
    }

    fclose(file);

    return strings;
}

int is_word(char *s, char **list, int len)
{
    if (!s || length(s) == 0)
    {
        return 0;
    }

    long min = 0, max = len, mid, cmp;
    while (min <= max)
    {
        mid = (min + max) / 2;
        cmp = strcmp_ign_case(list[mid], s);
        if (cmp == 0)
        {
            return 1;
        }
        else if (cmp < 0)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }
    return 0;
}

int find_shift()
{
    char **dict = init_dict();
    int len = 0;
    while (dict[len] != NULL)
    {
        len++;
    }

    int words = 30;
    char **file = init_file(words);

    int max_words = 0;
    int max_shift = 0;

    int cur_words;
    for (int i = 0; i < 26; i++)
    {
        cur_words = 0;
        for (int j = 0; j < words; j++)
        {
            if (is_word(shift(file[j], i), dict, len))
            {
                cur_words++;
            }
        }
        if (cur_words > max_words)
        {
            max_words = cur_words;
            max_shift = i;
        }
    }

    return max_shift;
}

void shift_file(int n)
{
    FILE *in = fopen("/home/bouch/ClionProjects/C/jaws_encr.txt", "r");
    FILE *out = fopen("/home/bouch/ClionProjects/C/jaws_decr.txt", "w");

    char c;
    while ((c = getc(in)) != EOF)
    {
        putc(shift_char(c, n), out);
    }

    fclose(in);
    fclose(out);
}