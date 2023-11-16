#include <stdio.h>
#include "linkedlist.h"

void linkedlist_display(PLIST list);

int main()
{
    int arr[5] = {5,4,3,2,1};
    PLIST list = linkedlist_create();
    //return -1 if failed to create the list
    if(list == NULL)
    {
        return -1;
    }

    //Add 5 nodes each at the beginging into the list
    for(int i=0; i<5;i++)
    {
        if(!linkedlist_addatbegin(list, &arr[i]))
            printf("Failed to add %d to the list!\n", arr[i]);
    }
    linkedlist_display(list);

    //Add 5 nodes each at the end into the list
    for(int i=0; i<5;i++)
    {
        if(!linkedlist_addatend(list, &arr[i]))
            printf("Failed to add %d to the list!\n", arr[i]);
    }
    linkedlist_display(list);

}

void linkedlist_display(PLIST list)
{
    if(list)
    {
        PNODE head = list->head;
        while(head)
        {
            printf("%d ", *(int*)head->data);
            head = head->next;
        }
        printf("\n");
    }
    else
        printf("!!! EMPTY LIST!!!\n");
}
