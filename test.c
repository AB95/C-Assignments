//
// Created by bouch on 01/09/15.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    struct linked_list *list = malloc(sizeof(struct linked_list));
    printf("%d\n", is_empty(list));
    add_to_start(list, "0");
    printf("%d\n", is_empty(list));
    add_to_end(list, "1");
    add_to_end(list, "2");
    add_to_start(list, "-1");
    add_to_end(list, "3");
    printf("%s %s\n", (char *)get_first(list)->data, (char *)get_last(list)->data);
    printf("%s\n", (char *)get(list, 4)->data);
    free(list);
    return 0;
}