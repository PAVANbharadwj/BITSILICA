#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *prev;
    struct node *next;
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
node* detectLoop(node* head)
{
    node *slow = head, *fast = head;
    while (fast && fast->next)
     {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL; 
}
void removeLoop(node* head)
 {
    node* meet = detectLoop(head);
    if (meet == NULL) {
        printf("No loop detected.\n");
        return;
    }

    node* start = head;
    while (start != meet)
    {
        start = start->next;
        meet = meet->next;
    }
    printf("Loop starts at node with data: %d\n", start->data);

    node* temp = start;
    while (temp->next != start)
        temp = temp->next;

    temp->next = NULL;
    start->prev = temp; 
    printf("Loop removed successfully.\n");
}
void printList(node* head)
{
    node* temp = head;
    int count = 0;
    printf("List: ");
    while (temp && count < 30)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("\n");
}
int main()
{
    node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    head->next->next->next->next->next = head->next->next;
    head->next->next->next->next->next->prev = head->next->next->next->next;

    printf("Checking for loop...\n");
    removeLoop(head);

    printf("\nAfter loop removal:\n");
    printList(head);

    return 0;
}