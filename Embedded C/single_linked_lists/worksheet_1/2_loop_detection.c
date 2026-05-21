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
void detectAndRemoveLoop(struct Node* head)
{
    struct Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
           slow = head;
            struct Node* prev = NULL;
            while (slow != fast)
            {
                prev = fast;
                slow = slow->next;
                fast = fast->next;
            }
            prev->next = NULL;
            printf("Loop detected and removed.\n");
            return;
        }
    }
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
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next->next = head->next;
    detectAndRemoveLoop(head);
    printf("List after removal: ");
    printList(head);
}
