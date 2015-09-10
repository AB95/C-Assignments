//
// Created by bouch on 03/09/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

int length(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

void lower(char *old, char *new)
{
    int len_old = length(old);
    for (int i = 0; i < len_old; i++)
    {
        if (old[i] >= 'A' && old[i] <= 'Z')
        {
            //Makes the letter lowercase
            new[i] = old[i] + 32;
        }
        else
        {
            new[i] = old[i];
        }
    }
    new[len_old - 1] = '\0';
}

char is_blank(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void lstrip(char *s)
{
    int i = 0, start = 0;
    while (s[i] != '\0')
    {
        if (!start && s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
        {
            start = i;
        }
        i++;
    }

    for (int j = 0; j < i - start; j++)
    {
        s[j] = s[start + j];
    }

    s[i - start] = '\0';
}

void rstrip(char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    int i = len - 1;
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' && i >= 0)
    {
        i--;
    }

    s[i + 1] = '\0';
}

void strip(char *s)
{
    lstrip(s);
    rstrip(s);
}

int index_of(char *h, char *n)
{
    int len_h = length(h);

    int len_n = length(n);

    for (int i = 0; i < len_h; i++)
    {
        if (h[i] == n[0])
        {
            for (int j = 0; j < len_n; j++)
            {
                if (h[i + j] != n[j])
                {
                    break;
                }
                return i;
            }
        }
    }
    return -1;
}

char *address_of(char *h, char *n)
{
    int len_h = length(h);

    int len_n = length(n);

    for (int i = 0; i < len_h; i++)
    {
        if (h[i] == n[0])
        {
            for (int j = 0; j < len_n; j++)
            {
                if (h[i + j] != n[j])
                {
                    break;
                }
                return &h[i];
            }
        }
    }
    return NULL;
}

int diff(char *s1, char *s2)
{
    int len1 = length(s1);

    int len2 = length(s2);

    int i = 0, j = 0, dif = 0;
    while (i < len1 && j < len2)
    {
        if (s1[i] != s2[j])
        {
            dif++;
        }
        i++;
        j++;
    }

    if (len1 > len2)
    {
        dif += len1 - len2;
    }
    else if (len2 > len1)
    {
        dif += len2 - len1;
    }

    return dif;
}

char *tab_to_space(char *s, int num_spaces)
{
    if (s == NULL)
    {
        return NULL;
    }

    int len = 0, tabs = 0;
    while (s[len] != '\0')
    {
        if (s[len] == '\t')
        {
            tabs++;
        }
        len++;
    }

    int new_len = (len - tabs) + (tabs * num_spaces);
    char *copy = malloc(sizeof(char) * (new_len + 1));

    int i = 0;
    for (int j = 0; j < len; j++)
    {
        if (s[j] == '\t')
        {
            for (int k = 0; k < num_spaces; k++)
            {
                copy[i++] = ' ';
            }
        }
        else
        {
            copy[i] = s[j];
            i++;
        }
    }

    copy[i] = '\0';
    return copy;
}

int strcmp_ign_case(char *s1, char *s2)
{
    int len1 = length(s1);

    int len2 = length(s2);

    char *lower_s1 = malloc(sizeof(char) * (len1 + 1));
    lower(s1, lower_s1);

    char *lower_s2 = malloc(sizeof(char) * (len1 + 1));
    lower(s2, lower_s2);

    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if (lower_s1[i] < lower_s2[j])
        {
            free(lower_s1);
            free(lower_s2);
            return -1;
        }
        else if (lower_s2[j] < lower_s1[i])
        {
            free(lower_s1);
            free(lower_s2);
            return 1;
        }
        i++;
        j++;
    }

    free(lower_s1);
    free(lower_s2);

    if (len1 < len2)
    {
        return -1;
    }
    else if (len2 < len1)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

char *distinct(char *s)
{
    int len = length(s);

    char *string = malloc(sizeof(char) * (len + 1));
    int string_len = 0;
    for (int i = 0; i < len; i++)
    {
        char duplicate = 0;
        for (int j = 0; j < string_len; j++)
        {
            if (s[i] == string[j])
            {
                duplicate = 1;
            }
        }
        if (!duplicate)
        {
            string[string_len++] = s[i];
        }
    }
    string[string_len++] = '\0';

    string = realloc(string, sizeof(char) * (string_len));
    return string;
}

char *pad(char *s, int d)
{
    if (s == NULL)
    {
        return NULL;
    }

    int len = length(s);

    int new_len = len;
    while (new_len % d != 0)
    {
        new_len++;
    }

    char *string = malloc(sizeof(char) * (new_len + 1));
    for (int i = 0; i < new_len; i++)
    {
        if (i < len)
        {
            string[i] = s[i];
        }
        else
        {
            string[i] = ' ';
        }
    }
    string[new_len] = '\0';

    return string;
}

int begins_with_ignore_case(char *s, char *pre)
{
    int len_s = length(s);

    int len_pre = length(pre);

    if (len_pre > len_s || len_pre == 0)
    {
        return 0;
    }

    char *lower_s = malloc(sizeof(char) * (len_s + 1));
    lower(s, lower_s);

    char *lower_pre = malloc(sizeof(char) * (len_pre + 1));
    lower(pre, lower_pre);

    for (int i = 0; i < len_pre; i++)
    {
        if (lower_s[i] != lower_pre[i])
        {
            free(lower_pre);
            free(lower_s);
            return 0;
        }
    }
    free(lower_pre);
    free(lower_s);
    return 1;
}

int ends_with_ignore_case(char *s, char *suff)
{
    int len_s = length(s);
    int len_suff = length(suff);

    if (len_suff > len_s || len_suff == 0)
    {
        return 0;
    }

    char *lower_s = malloc(sizeof(char) * (len_s + 1));
    lower(s, lower_s);

    char *lower_suff = malloc(sizeof(char) * (len_suff + 1));
    lower(suff, lower_suff);

    for (int i = 0; i < len_suff; i++)
    {
        if (lower_s[len_s - (len_suff - i)] != lower_suff[i])
        {
            free(lower_s);
            free(lower_suff);
            return 0;
        }
    }
    free(lower_s);
    free(lower_suff);
    return 1;
}


char *de_tab(char *s, int num_spaces)
{
    //I don't see how this is meant to be different from tab to space above
    return tab_to_space(s, num_spaces);
}

char *remove_chars(char *s1, char *s2)
{
    char *new_s2 = distinct(s2);

    int len1 = length(s1);
    int len2 = length(new_s2);

    char *s3 = malloc(sizeof(char) * (len1 + 1));

    int duplicate;
    int len3 = 0;
    for (int i = 0; i < len1; i++)
    {
        duplicate = 0;
        for (int j = 0; j < len2; j++)
        {
            if (s1[i] == new_s2[j])
            {
                duplicate = 1;
            }
        }
        if (!duplicate)
        {
            s3[len3++] = s1[i];
        }
    }
    s3[len3++] = '\0';
    return s3;
}

char *repeat(char *s, int x, char sep)
{
    if (s == NULL)
    {
        return NULL;
    }

    int len_s = length(s);
    int new_len = (len_s + 1) * x;

    char *string = malloc(sizeof(char) * new_len + 1);
    int len_string = 0;
    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < len_s; j++)
        {
            string[len_string++] = s[j];
        }
        string[len_string++] = sep;
    }
    for (int j = 0; j < len_s; j++)
    {
        string[len_string++] = s[j];
    }
    string[len_string++] = '\0';
    return string;
}

char *intersect(char *s1, char *s2)
{
    char *string1 = distinct(s1);
    char *string2 = distinct(s2);

    int len1 = length(string1);
    int len2 = length(string2);

    char *string3 = malloc(sizeof(char) * (len1));

    int len3 = 0;
    int duplicate = 0;
    for (int i = 0; i < len1; i++)
    {
        duplicate = 0;
        for (int j = 0; j < len2; j++)
        {
            if (string1[i] == string2[j])
            {
                duplicate = 1;
            }
        }
        if (duplicate)
        {
            string3[len3++] = string1[i];
        }
    }

    if (len3 == 0)
    {
        return NULL;
    }

    string3[len3++] = '\0';
    string3 = realloc(string3, sizeof(char) * len3);
    return string3;
}
