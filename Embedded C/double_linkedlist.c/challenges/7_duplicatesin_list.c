#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *prev, *next;
} node;

node* createnode(int data) 
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->prev = new->next = NULL;
    return new;
}
node* insertend(node* head) 
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node* new = createnode(data);

    if (head == NULL)
        return new;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new;
    new->prev = temp;
    return head;
}

void printlist(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void removeDuplicates(node* head)
{
    node* ptr1 = head;
    node* ptr2;
    node* dup;

    while (ptr1 != NULL && ptr1->next != NULL) 
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
         {
            if (ptr1->data == ptr2->data)
             {
                dup = ptr2;
                ptr2 = ptr2->next;
                if (dup->prev)
                    dup->prev->next = dup->next;
                if (dup->next)
                    dup->next->prev = dup->prev;

                free(dup);
             }
                 else
             {
                ptr2 = ptr2->next;
             }
        }
        ptr1 = ptr1->next;
    }
}

int main() 
{
    int n;
    node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        head = insertend(head);
    }
    printf("\nOriginal List: ");
    printlist(head);
    removeDuplicates(head);
    printf("List after removing duplicates: ");
    printlist(head);
}