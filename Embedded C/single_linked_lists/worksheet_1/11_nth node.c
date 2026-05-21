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
void insertEnd(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node* head)
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void nthFromEnd(struct Node* head, int n)
{
    struct Node *main_ptr = head, *ref_ptr = head;

    int count = 0;
    while (count < n)
    {
        if (ref_ptr == NULL)
        {
            printf("List has fewer than %d nodes.\n", n);
            return;
        }
        ref_ptr = ref_ptr->next;
        count++;
    }
    while (ref_ptr != NULL)
    {
        main_ptr = main_ptr->next;
        ref_ptr = ref_ptr->next;
    }
    printf("Node %d from end is: %d\n", n, main_ptr->data);
}
int main() 
{
    struct Node* head = NULL;
    int n, val, pos;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }
    printf("Enter position from end: ");
    scanf("%d", &pos);
    printf("Linked list: ");
    printList(head);
    nthFromEnd(head, pos);
}
