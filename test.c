//
// Created by bouch on 01/09/15.
//

#include <stdio.h>
#include "strings.h"

int main()
{
    char str1[] = "a";
    char str2[] = "a";
    printf("%d\n", strcmp_ign_case(str1, str2));

    return 0;
}