//
// Created by bouch on 12/09/15.
//

#ifndef C_LINKED_LIST_H
#define C_LINKED_LIST_H

typedef struct node node;

struct node
{
    void *data;
    node *next;
};

struct linked_list{
    node *head;
};

void add_to_start(struct linked_list *list, void *data);
void add_to_end(struct linked_list *list, void *data);
node *get_first(struct linked_list *list);
node *get_last(struct linked_list *list);


#endif //C_LINKED_LIST_H
