//
// Created by bouch on 01/09/15.
//

#include <stdio.h>
#include "strings.h"

int main()
{
    char str[] = "abcd e";
    char pre[] = "";
    printf("%d\n", ends_with_ignore_case(str, pre));

    return 0;
}