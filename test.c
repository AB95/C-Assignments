//
// Created by bouch on 01/09/15.
//

#include <stdio.h>
#include "crypto.h"

int main()
{
    char **strings = init_dict();
    int i = 0;
    while(strings[i] != NULL)
    {
        printf("%s %d\n", strings[i], i);
        i++;
    }

    return 0;
}