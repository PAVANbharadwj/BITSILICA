#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void printlist(struct node *head);

struct node* createnode(int a)
{
    struct node *temp = NULL, *new = NULL, *head = NULL;
    printf("\nEnter %d data values: ", a);

    for (int i = 0; i < a; i++)
    {
        new = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &new->data);
        new->next = NULL;

        if (head == NULL)
        {
            head = new;
            temp = head;
        }
        else
        {
            temp->next = new;
            temp = new;
        }
    }
    return head;
}

void alternatemerging(struct node *head1, struct node *head2)
{
    struct node *p1 = head1, *p2 = head2;
    struct node *next1, *next2;

    while (p1 != NULL && p2 != NULL)
    {
        next1 = p1->next;
        next2 = p2->next;

        p1->next = p2;
        if (next1 == NULL)
            break;
        p2->next = next1;
        p1 = next1;
        p2 = next2;
    }

    printf("\nMerged list (alternate): ");
    printlist(head1);
    printf("\n");
}

void printlist(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int a;
    struct node *head = NULL, *head1 = NULL;
    printf("Enter number of nodes to create: ");
    scanf("%d", &a);
    printf("\nEnter elements for first list:\n");
    head = createnode(a);
    printf("\nEnter elements for second list:\n");
    head1 = createnode(a);
    alternatemerging(head, head1);
}
