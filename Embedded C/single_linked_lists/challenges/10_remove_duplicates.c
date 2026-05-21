#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct node* createList(int n)
{
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}
void removeDuplicates(struct node *head)
{
    struct node *curr = head;
    while (curr != NULL) {
        struct node *prev = curr;
        struct node *temp = curr->next;

        while (temp != NULL) {
            if (temp->data == curr->data) 
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } 
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}
void printList(struct node *head) 
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct node *head = createList(n);
    printf("\nOriginal list:\n");
    printList(head);
    removeDuplicates(head);
    printf("\nList after removing duplicates:\n");
    printList(head);
}