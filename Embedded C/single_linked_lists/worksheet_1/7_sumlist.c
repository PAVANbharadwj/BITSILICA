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
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}
void printList(struct Node* head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node* addLists(struct Node* l1, struct Node* l2)
{
    struct Node* result = NULL;
    struct Node* tail = NULL;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
    struct Node* newNode = createNode(sum);
    if (result == NULL)
            result = tail = newNode;
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}
int main()
{
    struct Node *num1 = NULL, *num2 = NULL, *sum = NULL;
    int n1, n2, val;

    printf("Enter number of digits in first number: ");
    scanf("%d", &n1);
    printf("Enter digits (in reverse order): ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &val);
        insertEnd(&num1, val);
    }

    printf("Enter number of digits in second number: ");
    scanf("%d", &n2);
    printf("Enter digits (in reverse order): ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &val);
        insertEnd(&num2, val);
    }
    printf("First number:  ");
    printList(num1);
    printf("Second number: ");
    printList(num2);
    sum = addLists(num1, num2);
    printf("Sum list:      ");
    printList(sum);
}
