#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
}NODE, *PNODE;

typedef struct LinkedList
{
    PNODE head;
}LIST, *PLIST;

PLIST linkedlist_create();
PNODE node_create(void *data);
PNODE linkedlist_addatbegin(PLIST list, void* data);
PNODE linkedlist_addatend(PLIST list, void* data);

#endif // _LINKEDLIST_