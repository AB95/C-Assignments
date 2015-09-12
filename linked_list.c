//
// Created by bouch on 12/09/15.
//

void add_to_start(struct linked_list *list, void *info)
{
    node *new = malloc(sizeof(node));
    new->data = info;
    new->next = NULL;
    if(list->head == NULL)
    {
        list->head = new;
    }
    else
    {
        node *temp = list->head;
        list->head = new;
        new->next = temp;
    }
}

void add_to_end(struct linked_list *list, void *info)
{
    node *new = malloc(sizeof(node));
    new->data = info;
    new->next = NULL;

    node *last = get_last(list);
    if (last == NULL)
    {
        add_to_start(list, info);
    }
    else
    {
        last->next = new;
    }
}

node *get_first(struct linked_list *list)
{
    return list->head;
}

node *get_last(struct linked_list *list)
{
    node *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}