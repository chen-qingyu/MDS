#include "LinkedList.h"

#include <limits.h> // INT_MAX
#include <stdlib.h> // malloc free

#include "../common/check_bounds.h"
#include "../common/check_empty.h"
#include "../common/check_full.h"
#include "../common/check_pointer.h"

struct node
{
    // Data stored in the node.
    ListItem data;

    // Successor.
    struct node* next;
};

struct list
{
    // Number of elements.
    int count;

    // Pointer to the header (rank = -1).
    struct node* header;
};

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

List* LinkedList_Create(void)
{
    List* list = (List*)malloc(sizeof(List));
    check_pointer(list);

    list->count = 0;
    list->header = (struct node*)malloc(sizeof(struct node));
    check_pointer(list->header);
    list->header->next = NULL;

    return list;
}

void LinkedList_Destroy(List* self)
{
    while (self->header)
    {
        struct node* next = self->header->next;
        free(self->header);
        self->header = next;
    }
    free(self);
}

int LinkedList_Size(const List* self)
{
    return self->count;
}

bool LinkedList_IsEmpty(const List* self)
{
    return self->count == 0;
}

ListItem LinkedList_At(const List* self, int i) // self[i]
{
    check_bounds(i, -self->count, self->count);

    i = i >= 0 ? i : i + self->count;

    struct node* current = self->header->next;

    for (int j = 0; j < i; ++j)
    {
        current = current->next;
    }

    return current->data;
}

int LinkedList_Find(const List* self, ListItem data)
{
    int index = 0;
    struct node* current = self->header->next;

    while (current != NULL && current->data != data)
    {
        current = current->next;
        index++;
    }

    return current ? index : LIST_NOT_FOUND;
}

void LinkedList_Insert(List* self, int i, ListItem data)
{
    check_full(self->count, INT_MAX);

    check_bounds(i, 0, self->count + 1);

    struct node* node = (struct node*)malloc(sizeof(struct node));
    check_pointer(node);
    node->data = data;

    struct node* tmp = self->header;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    node->next = tmp->next;
    tmp->next = node;

    ++self->count;
}

void LinkedList_Delete(List* self, int i)
{
    check_empty(self->count);

    check_bounds(i, 0, self->count);

    struct node* tmp = self->header;
    for (int j = 0; j < i; j++)
    {
        tmp = tmp->next;
    }
    struct node* node = tmp->next;
    tmp->next = node->next;
    free(node);
    node = NULL;

    --self->count;
}

void LinkedList_Traverse(List* self, void (*p_trav)(ListItem data))
{
    for (struct node* cur = self->header->next; cur != NULL; cur = cur->next)
    {
        p_trav(cur->data);
    }
}

void LinkedList_Reverse(List* self)
{
    struct node* pre = self->header->next;
    self->header->next = NULL;

    while (pre)
    {
        struct node* tmp = pre;
        pre = pre->next;
        tmp->next = self->header->next;
        self->header->next = tmp;
    }
}