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
struct Node* merge(struct Node* a, struct Node* b)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (a && b)
    {
        if (a->data <= b->data) 
        {
            tail->next = a;
            a = a->next;
        }
         else
        {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a) ? a : b;
    return dummy.next;
}
void printList(struct Node* head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}
int main() 
{
    struct Node* a = createNode(1);
    a->next = createNode(3);
    a->next->next = createNode(5);

    struct Node* b = createNode(2);
    b->next = createNode(4);
    b->next->next = createNode(6);

    struct Node* merged = merge(a, b);
    printList(merged);
}
