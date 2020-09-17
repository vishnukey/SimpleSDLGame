#include <list.h>
#include <stdlib.h>

list* end(list* l){
        for(; l->next != NULL; l = l->next);
        return l;
}

struct node* list_push(list* l, size_t dataSize)
{
        list* next = list_new();
        list* theEnd = end(l);

        next->data = malloc(dataSize);
        next->next = NULL;
        next->prev = theEnd;

        theEnd->next = next;

        return next;
}

void list_pop(list* l)
{
        list* theEnd = end(l);
        list* newEnd = theEnd->prev;
        newEnd->next = NULL;

        free(theEnd->data);
        free(theEnd);
}

list* list_new(void)
{
       list* l = (list*)malloc(sizeof(list));
       l->data = NULL;
       l->next = NULL;
       l->prev = NULL;
       return l;
}

void list_free(list* l)
{
        if (l->next != NULL) list_free(l->next);
        if (l->data != NULL) free(l->data);
        free(l);
}

struct node* list_get(list* l, int index)
{
        if (l == NULL) return NULL;
        if (index == 0) return l;
        return list_get(l->next, index - 1);
}

void list_remove(list* l, int index)
{
        list* target = list_get(l, index);
        if (target == NULL) return;

        remove_node(target);

        /*list* prev = target->prev;
        list* next = target->next;

        prev->next = next;
        next->prev = prev;

        free(target->data);
        free(target);*/
}

struct node* remove_node(struct node* item)
{
       list* prev = item->prev;
       list* next = item->next;

       prev->next = next;
       if (next != NULL)
               next->prev = prev;

       free(item->data);
       free(item);

       return next;
}


