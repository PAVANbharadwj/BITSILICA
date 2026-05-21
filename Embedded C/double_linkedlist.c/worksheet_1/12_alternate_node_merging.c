#include <stdio.h>
#include <stdlib.h>

typedef struct node
 {
    int data;
    struct node *next;
    struct node *prev;
} node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
node* insertEnd(node* head)
 {
    int data;
    printf("Enter data: ");
    scanf("%d", &data);
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

void printList(node* head) 
{
    node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node* mergeAlternate(node* head1, node* head2) 
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    node *p1 = head1, *p2 = head2;
    node *next1, *next2;
    while (p1 != NULL && p2 != NULL)
    {
        next1 = p1->next;
        next2 = p2->next;

        p1->next = p2;
        p2->prev = p1;

         if (next1 != NULL)
         next1->prev = p2;

        p2->next = next1;

        p1 = next1;
        p2 = next2;
    }
    return head1;
}
int main() 
{
    node *head1 = NULL, *head2 = NULL;
    int n1, n2;

    printf("Enter number of nodes in List1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
        head1 = insertEnd(head1);

    printf("Enter number of nodes in List2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
        head2 = insertEnd(head2);

    printf("\nList1: ");
    printList(head1);
    printf("List2: ");
    printList(head2);

    head1 = mergeAlternate(head1, head2);

    printf("\nMerged List (Alternate): ");
    printList(head1);
}