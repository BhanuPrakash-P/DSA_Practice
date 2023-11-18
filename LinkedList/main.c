#include <stdio.h>
#include "linkedlist.h"

void linkedlist_display(PLIST list, char *caller);

int main()
{
    int arr[5] = {5,4,3,2,1};
    int arr2[5] = {6,7,8,9,10};
    PLIST list = linkedlist_create();
    //return -1 if failed to create the list
    if(list == NULL)
    {
        return -1;
    }

    //Add 5 nodes each at the beginning into the list
    for(int i=0; i<5;i++)
    {
        if(!linkedlist_addatbegin(list, &arr[i]))
            printf("Failed to add %d to the list!\n", arr[i]);
    }
    linkedlist_display(list, "LIST after linkedlist_addatbegin");

    //Add 5 nodes each at the end into the list
    for(int i=0; i<5;i++)
    {
        if(!linkedlist_addatend(list, &arr2[i]))
            printf("Failed to add %d to the list!\n", arr2[i]);
    }
    linkedlist_display(list, "LIST after linkedlist_addatend");

    //Delete two nodes from beginning
    linkedlist_deleteatbegin(list);
    linkedlist_display(list, "LIST after linkedlist_deleteatbegin");
    linkedlist_deleteatbegin(list);
    linkedlist_display(list, "LIST after linkedlist_deleteatbegin");

    //Delete two nodes from end
    linkedlist_deleteatend(list);
    linkedlist_display(list, "LIST after linkedlist_deleteatend");
    linkedlist_deleteatend(list);
    linkedlist_display(list, "LIST after linkedlist_deleteatend");

    //Delete some nodes from specific positions
    linkedlist_deleteatpos(list, 1);
    linkedlist_display(list, "LIST after linkedlist_deleteatpos 1"); 
    linkedlist_deleteatpos(list, 5);
    linkedlist_display(list, "LIST after linkedlist_deleteatpos 5"); 
    linkedlist_deleteatpos(list, 3);
    linkedlist_display(list, "LIST after linkedlist_deleteatpos 3");  
    linkedlist_deleteatpos(list, 5);
    linkedlist_display(list, "LIST after linkedlist_deleteatpos 5");  
    linkedlist_deleteatpos(list, -1);
    linkedlist_display(list, "LIST after linkedlist_deleteatpos -1");  

}

void linkedlist_display(PLIST list, char *caller)
{
    printf("%s: ", caller);
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
