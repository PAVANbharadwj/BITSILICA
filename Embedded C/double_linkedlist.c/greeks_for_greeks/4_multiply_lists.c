#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* createNode(int data) 
{
    node* new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

void insertEnd(node** head, int data)
{
    node* new = createNode(data);
    if (*head == NULL) {
        *head = new;
        return;
    }
    node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new;
}

void printList(node* head) 
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

long long listToNumber(node* head)
{
    long long num = 0;
    while (head != NULL) {
        num = num * 10 + head->data;
        head = head->next;
    }
    return num;
}

node* numberToList(long long num)
{
    if (num == 0)
        return createNode(0);

    node* head = NULL;
    node* tail = NULL;
    int digits[50];
    int count = 0;

    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    for (int i = count - 1; i >= 0; i--)
    {
        node* new = createNode(digits[i]);
        if (head == NULL)
            head = tail = new;
        else
        {
            tail->next = new;
            tail = new;
        }
    }
    return head;
}

node* multiplyLists(node* l1, node* l2)
{
    long long num1 = listToNumber(l1);
    long long num2 = listToNumber(l2);
    long long result = num1 * num2;
    return numberToList(result);
}

int main()
 {
    node *l1 = NULL, *l2 = NULL, *res = NULL;

    insertEnd(&l1, 3);
    insertEnd(&l1, 4);
    insertEnd(&l1, 2);

    insertEnd(&l2, 1);
    insertEnd(&l2, 2);

    printf("List 1: ");
    printList(l1);
    printf("List 2: ");
    printList(l2);

    res = multiplyLists(l1, l2);

    printf("Result: ");
    printList(res);
    
}