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
    int size;
};

char is_empty(struct linked_list *list);
node *get(struct linked_list *list, int index);
void add_to_start(struct linked_list *list, void *info);
void add_to_end(struct linked_list *list, void *info);
node *get_first(struct linked_list *list);
node *get_last(struct linked_list *list);


#endif //C_LINKED_LIST_H
