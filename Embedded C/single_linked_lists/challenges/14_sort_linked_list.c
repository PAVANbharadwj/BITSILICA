#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertEnd(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void sortList(struct Node* head)
{
    struct Node* i;
    struct Node* j;
    int temp;

    if (head == NULL)
        return;
    for (i = head; i->next != NULL; i = i->next) 
    {
        for (j = head; j->next != NULL; j = j->next) 
        {
            if (j->data > j->next->data)
             {
                temp = j->data;
                j->data = j->next->data;
                j->next->data = temp;
            }
        }
    }
}

int main()
 {
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Original list: ");
    printList(head);
    sortList(head);
    printf("Sorted list:   ");
    printList(head);
}
