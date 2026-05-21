#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
} node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

node* insertEnd(node* head, int data)
{
    node* newNode = createNode(data);
    if (head == NULL)
        return newNode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
node* createListFromArray(int arr[], int n)
{
    node* head = NULL;
    for (int i = 0; i < n; i++)
        head = insertEnd(head, arr[i]);
    return head;
}

node* mergeLists(node* list1, node* list2)
{
    if (!list1) 
        return list2;
    if (!list2)
        return list1;

    if (list1->data <= list2->data)
    {
        list1->next = mergeLists(list1->next, list2);
        if (list1->next)
            list1->next->prev = list1;
        list1->prev = NULL;
        return list1;
    } else
    {
        list2->next = mergeLists(list1, list2->next);
        if (list2->next)
            list2->next->prev = list2;
        list2->prev = NULL;
        return list2;
    }
}
void printList(node* head) 
{
    node* temp = head;
    printf("Merged Doubly Linked List:\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    node* list1 = createListFromArray(arr1, n1);
    node* list2 = createListFromArray(arr2, n2);
    
    node* merged = mergeLists(list1, list2);
    printList(merged);
}