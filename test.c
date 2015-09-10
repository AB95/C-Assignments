//
// Created by bouch on 01/09/15.
//

#include <stdio.h>
#include "strings.h"

int main()
{
    char str1[] = "buggy";
    char str2[] = "aguert";
    printf("%s\n", remove_chars(str1, str2));

    return 0;
}