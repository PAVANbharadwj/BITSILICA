#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
} node;

node* createNode(int data) 
{
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
node* insertEnd(node* head, int data)
{
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
node* deleteFromHead(node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Deleted head node.\n");
    return head;
}
node* reverseList(node* head) 
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return NULL;
    }
    node* current = head;
    node* temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;

    printf("List reversed.\n");
    return head;
}
void printList(node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    node* temp = head;
    printf("List (forward): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void printReverse(node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    printf("List (reverse): ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
void middleElement(node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    printf("Middle element: %d\n", slow->data);
}
void elementFromLast(node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid n!\n");
        return;
    }
    node* last = head;
    int len = 0;
    while (last->next != NULL)
    {
        last = last->next;
        len++;
    }
    len++;
    if (n > len)
    {
        printf("n is greater than list length (%d)\n", len);
        return;
    }
    for (int i = 1; i < n; i++)
        last = last->prev;
    printf("%dth element from last is %d\n", n, last->data);
}
void freeList(node* head)
{
    node* temp;
    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("All nodes freed.\n");
}
int main() 
{
    node* head = NULL;
    int choice, val;
    while (1) 
    {
        printf("\nMenu:\n");
        printf("1 - Insert at end\n");
        printf("2 - Delete from head\n");
        printf("3 - Reverse list\n");
        printf("4 - Print list (forward)\n");
        printf("5 - Print list (reverse)\n");
        printf("6 - nth element from last\n");
        printf("7 - Middle element\n");
        printf("8 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                head = insertEnd(head, val);
                break;
            case 2:
                head = deleteFromHead(head);
                break;
            case 3:
                head = reverseList(head);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                printReverse(head);
                break;
            case 6:
                elementFromLast(head);
                break;
            case 7:
                middleElement(head);
                break;
            case 8:
                freeList(head);
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}