//
// Created by bouch on 01/09/15.
//

#include <stdio.h>
#include "strings.h"

int main()
{
    char string[] = "abc\tdff\tff\t";
    printf("%sd\n", tab_to_space(string, 1));

    return 0;
}