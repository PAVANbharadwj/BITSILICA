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
void insertEnd(struct node** head, int data)
{
    struct node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL)
    temp = temp->next;
    temp->next = newNode;
}
void printlist(struct node *head)
{
    struct node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void deletefromhead(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted head node.\n");
}

void reverselist(struct node **head)
{
    struct node *prev = NULL, *curr = *head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
    printf("List reversed.\n");
}
void middle_element(struct node* head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    struct node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("The middle element is %d\n", slow->data);
}
void elementfromlast(struct node *head)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    struct node *main = head, *ref = head;
    for (int i = 0; i < n; i++)
    {
        if (ref == NULL)
        {
            printf("n is greater than list length.\n");
            return;
        }
        ref = ref->next;
    }
    while (ref != NULL)
    {
        main = main->next;
        ref = ref->next;
    }
    printf("%dth element from last is %d\n", n, main->data);
}
void free_data(struct node*head)
{
    struct node* temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    if(head==NULL)
    printf("All nodes freed\n");
    exit(0);
}
int main()
{
    int choice, val;
    struct node* head = NULL;
    printf("Enter number of nodes: ");
    while (1)
    {
        printf("\nMenu:\n");
        printf("1 - Insert at end\n");
        printf("2 - Delete from head\n");
        printf("3 - Reverse list\n");
        printf("4 - Print list\n");
        printf("5 - nth element from last\n");
        printf("6 - Middle element\n");
        printf("7 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;
            case 2:
                deletefromhead(&head);
                break;
            case 3:
                reverselist(&head);
                break;
            case 4:
                printlist(head);
                break;
            case 5:
                elementfromlast(head);
                break;
            case 6:
                middle_element(head);
                break;
            case 7:
                free_data(head);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}