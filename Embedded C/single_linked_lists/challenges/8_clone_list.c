#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *next;
    struct node *random;
};
struct node* newNode(char data) 
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    n->random = NULL;
    return n;
}
struct node* cloneList(struct node* head) {
    if (!head) return NULL;

    struct node *curr = head, *temp;
      while (curr) {
        temp = curr->next;
        curr->next = newNode(curr->data);
        curr->next->next = temp;
        curr = temp;
    }
    curr = head;
    while (curr) 
    {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    curr = head;
    struct node* cloneHead = head->next;
    struct node* cloneCurr = cloneHead;
    while (curr && cloneCurr)
    {
        curr->next = cloneCurr->next;
        curr = curr->next;
        if (curr)
            cloneCurr->next = curr->next;
        cloneCurr = cloneCurr->next;
    }

    return cloneHead;
}
void printList(struct node* head)
{
    while (head)
    {
        printf("Node %c", head->data);
        if (head->random)
            printf(" (rand→%c)", head->random->data);
        else
            printf(" (rand→NULL)");
        printf("\n");
        head = head->next;
    }
}
int main()
{
    struct node *A = newNode('A');
    struct node *B = newNode('B');
    struct node *C = newNode('C');

    A->next = B;
    B->next = C;

    A->random = C;  
    B->random = A;  
    C->random = B; 

    printf("Original list:\n");
    printList(A);
    struct node* cloned = cloneList(A);
    printf("\nCloned list:\n");
    printList(cloned);
}