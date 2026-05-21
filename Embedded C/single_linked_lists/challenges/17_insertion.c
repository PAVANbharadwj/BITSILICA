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

struct Node* findIntersection(struct Node* head1, struct Node* head2)
{
    struct Node* a = head1;
    struct Node* b = head2;

    while (a != b)
    {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    return a; 
}
int main()
{
    struct Node* common = createNode(3);
    common->next = createNode(4);
    struct Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = common;
    struct Node* head2 = createNode(5);
    head2->next = common;
    struct Node* inter = findIntersection(head1, head2);

    if (inter)
        printf("Intersection found at node with data: %d\n", inter->data);
    else
        printf("No intersection found\n");
}