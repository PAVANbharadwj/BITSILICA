#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    struct Node* random;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;
    return newNode;
}
void printList(struct Node* head)
{
    while (head)
    {
        printf("Data = %d, ", head->data);
        if (head->random)
            printf("Random = %d\n", head->random->data);
        else
            printf("Random = NULL\n");
        head = head->next;
    }
    printf("\n");
}

struct Node* copyList(struct Node* head)
{
    if (!head) return NULL;
    struct Node* temp = head;
    while (temp) 
    {
        struct Node* copy = createNode(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    struct Node* copyHead = head->next;
    struct Node* copy = copyHead;
    temp = head;
    while (temp && copy)
    {
        temp->next = copy->next;
        temp = temp->next;
        if (temp)
            copy->next = temp->next;
        copy = copy->next;
    }
    return copyHead;
}

int main()
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(7);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head;
    head->next->next->next->next->random = head->next->next;

    printf("Original list:\n");
    printList(head);

    struct Node* copied = copyList(head);

    printf("Copied list:\n");
    printList(copied);
}