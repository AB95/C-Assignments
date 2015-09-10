//
// Created by bouch on 03/09/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

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

    for (int j = 0; j < i-start; j++)
    {
        s[j] = s[start+j];
    }

    s[i-start] = '\0';
}

void rstrip(char *s)
{
    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }

    int i = len-1;
    while(s[i] == ' ' || s[i] == '\t' || s[i] == '\n' && i >= 0)
    {
        i--;
    }

    s[i+1] = '\0';
}

void strip(char *s)
{
    lstrip(s);
    rstrip(s);
}

int index_of(char *h, char *n)
{
    int len_h = 0;
    while(h[len_h] != '\0')
    {
        len_h++;
    }

    int len_n = 0;
    while(n[len_n] != '\0')
    {
        len_n++;
    }

    for(int i = 0; i < len_h; i++)
    {
        if(h[i] == n[0])
        {
            for(int j = 0; j < len_n; j++)
            {
                if(h[i+j] != n[j])
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
    int len_h = 0;
    while(h[len_h] != '\0')
    {
        len_h++;
    }

    int len_n = 0;
    while(n[len_n] != '\0')
    {
        len_n++;
    }

    for(int i = 0; i < len_h; i++)
    {
        if(h[i] == n[0])
        {
            for(int j = 0; j < len_n; j++)
            {
                if(h[i+j] != n[j])
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
    int len1 = 0;
    while(s1[len1] != '\0')
    {
        len1++;
    }

    int len2 = 0;
    while(s2[len2] != '\0')
    {
        len2++;
    }

    int i=0, j=0, dif=0;
    while(i < len1 && j < len2)
    {
        if(s1[i] != s2[j])
        {
            dif++;
        }
        i++;
        j++;
    }

    if(len1 > len2)
    {
        dif += len1 - len2;
    }
    else if(len2 > len1)
    {
        dif += len2 - len1;
    }

    return dif;
}

char *tab_to_space(char *s, int num_spaces)
{
    int len = 0, tabs = 0;
    while(s[len] != '\0')
    {
        if(s[len] == '\t')
        {
            tabs++;
        }
        len++;
    }

    int new_len = (len-tabs) + (tabs*num_spaces);
    char *copy = malloc(sizeof(char)*(new_len+1));

    int i = 0;
    for(int j = 0; j < len; j++)
    {
        if(s[j] == '\t')
        {
            for(int k = 0; k < num_spaces; k++)
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
    int len1 = 0;
    while(s1[len1] != '\0')
    {
        len1++;
    }

    int len2 = 0;
    while(s2[len2] != '\0')
    {
        len2++;
    }

    char *lower_s1 = malloc(sizeof(char)*(len1+1));
    for(int i = 0; i < len1; i++)
    {
        if(s1[i] >= 'A' && s1[i] <= 'Z')
        {
            //Makes the letter lowercase
            lower_s1[i] = s1[i] + 22;
        }
        else
        {
            lower_s1[i] = s1[i];
        }
    }

    char *lower_s2 = malloc(sizeof(char)*(len1+1));
    for(int i = 0; i < len2; i++)
    {
        if(s2[i] >= 'A' && s2[i] <= 'Z')
        {
            //Makes the letter lowercase
            lower_s2[i] = s2[i] + 22;
        }
        else
        {
            lower_s2[i] = s2[i];
        }
    }

    int i = 0, j = 0;
    while(i < len1 && j < len2)
    {
        if(lower_s1[i] < lower_s2[j])
        {
            return -1;
        }
        else if(lower_s2[j] < lower_s1[i])
        {
            return 1;
        }
        i++;
        j++;
    }

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
    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }

    char *string = malloc(sizeof(char)*(len+1));
    int string_len = 0;
    for(int i = 0; i < len; i++)
    {
        char duplicate = 0;
        for(int j = 0; j < string_len; j++)
        {
            if(s[i] == string[j])
            {
                duplicate = 1;
            }
        }
        if(!duplicate)
        {
            string[string_len++] = s[i];
        }
    }
    string[string_len++] = '\0';

    string = realloc(string, sizeof(char)*(string_len));
    return string;
}

char *pad(char *s, int d)
{
    if(s == NULL)
    {
        return NULL;
    }

    int len = 0;
    while(s[len] != '\0')
    {
        len++;
    }

    int new_len = len;
    while(new_len%d != 0)
    {
        new_len++;
    }

    char *string = malloc(sizeof(char) * (new_len+1));
    for(int i = 0; i < new_len; i++)
    {
        if(i < len)
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
