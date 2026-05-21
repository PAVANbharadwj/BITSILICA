#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* createnode(node* head)
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;

    if (head == NULL)
        return new;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    return head;
}

void printlist(node* head) 
{
    printf("\nList: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node* removeNthFromEnd(node* head, int n)
{
    node* fast = head;
    node* slow = head;

    for (int i = 0; i < n; i++) 
    {
        fast = fast->next;
    }

    if (fast == NULL) 
    {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while (fast->next != NULL) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    node* temp = slow->next;
    slow->next = slow->next->next;
    free(temp);

    return head;
}

int main() 
{
    int n, count;
    node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++)
        head = createnode(head);

    printlist(head);

    printf("Enter N (delete Nth node from end): ");
    scanf("%d", &n);

    head = removeNthFromEnd(head, n);

    printlist(head);

}