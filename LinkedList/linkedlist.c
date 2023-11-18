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
    PNODE newNode = NULL;
    if(list && data)
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
    PNODE newNode = NULL;
    if(list && data)
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

PNODE linkedlist_addatpos(PLIST list, void* data, int pos)
{
    PNODE newNode = NULL;
    if(list && data)
    {
        newNode = node_create(data);
        if(pos == 1)
        {
            newNode->next = list->head;
            list->head = newNode;
        }
        else
        {
            PNODE cur = list->head;
            for(int count=1; cur && count<=pos-2; count++)
            {
                cur = cur->next;
            }
            if(cur)
            {
                newNode->next = cur->next;
                cur->next = newNode;
            }
        }
    }
    return newNode;
}

void linkedlist_deleteatbegin(PLIST list)
{
    if(list && list->head)
    {
        PNODE head = list->head;
        PNODE temp = head;
        list->head = head->next;
        free(temp);
    }
    else
    {
        printf("%s:!!!LIST IS EMPTY!!!\n", __func__);
    }

}

void linkedlist_deleteatend(PLIST list)
{
    if(list && list->head)
    {
        PNODE curNode = list->head;
        if(!curNode->next)
        {
            free(curNode);
            list->head = NULL;
        }
        else
        {
            while(curNode->next->next)
            {
                curNode = curNode->next;
            }
            free(curNode->next);
            curNode->next = NULL;
        }
    }
    else
    {
        printf("%s:!!!LIST IS EMPTY!!!\n", __func__);
    }
}

void linkedlist_deleteatpos(PLIST list, int pos)
{
    if(list && list->head)
    {
        PNODE curNode = list->head;
        if(pos == 1)
        {
            list->head = curNode->next;
            free(curNode);
        }
        else
        {
            int count=1;
            for(; curNode->next->next && count<=pos-2; count++)
            {
                curNode = curNode->next;
            }
            if(count>pos-1 || count<pos-2)
            {
                printf("%s: INVALID POSITION!!!\n", __func__);
            }
            else
            {
                PNODE tempNode = curNode->next;
                curNode->next = curNode->next->next;
                free(tempNode);
            }
        }
    }
    else
    {
        printf("%s:!!!LIST IS EMPTY!!!\n", __func__);
    }
}