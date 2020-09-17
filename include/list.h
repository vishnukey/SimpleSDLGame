#ifndef LIST__H__
#define LIST__H__

#include <stddef.h>

typedef struct node{
        void* data;
        struct node* next;
        struct node* prev;
} list;

list* list_new(void);
void list_free(list* l);

struct node* list_push(list* l, size_t dataSize);
void list_pop(list* l);

struct node* list_get(list* l, int index);
void list_remove(list* l, int index);
struct node* remove_node(struct node* item);

#endif
