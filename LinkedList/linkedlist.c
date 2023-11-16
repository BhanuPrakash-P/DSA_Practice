#include "linkedlist.h"

PLIST linkedlist_create()
{
    PLIST list = (PLIST) malloc(sizeof(LIST));
    if(list == NULL)
    {
        printf("Failed to create a list\n");
    }
    else
    {
        list->head = NULL;
    }
    return list;
}

PNODE node_create(void *data)
{
    PNODE node = (PNODE) malloc(sizeof(NODE));
    if(node == NULL)
    {
        printf("Failed to create a new node\n");
    }
    else
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

PNODE linkedlist_addatbegin(PLIST list, void* data)
{
    PNODE newNode;
    if(list == NULL || data == NULL)
        newNode = NULL;
    else
    {
        newNode = node_create(data);
        if(newNode == NULL)
        {
            //Do nothing
        }
        else
        {
            if(list->head == NULL)
                list->head = newNode;
            else
            {
                newNode->next = list->head;
                list->head = newNode;
            }
        }

    }
    return newNode;
} 

PNODE linkedlist_addatend(PLIST list, void* data)
{
    PNODE newNode;
    if(list == NULL || data == NULL)
        newNode = NULL;
    else
    {
        newNode = node_create(data);
        if(list->head == NULL)
        {
#ifdef ENABLE_DEBUG
            printf("List is currently EMPTY, adding the first node\n");
#endif
            list->head = newNode;
        }
        else
        {
            PNODE headNode= list->head;
            while(headNode->next != NULL)
            {
                headNode = headNode->next;
            }
            headNode->next = newNode;
        }
    }
    return newNode;

}

