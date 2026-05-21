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
    while (temp->next != NULL)
    temp = temp->next;
    temp->next = newNode;
}
int isPalindrome(struct Node* head)
{
    int arr[100], i = 0;
    struct Node* temp = head;

    while (temp != NULL)
    {
        arr[i++] = temp->data;
        temp = temp->next;
    }

    int start = 0, end = i - 1;
    while (start < end)
    {
        if (arr[start] != arr[end])
        return 0;
        start++;
        end--;
    }
    return 1;
}
int main()
{
    struct Node* head = NULL;
    int n, val;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insertEnd(&head, val);
    }

    if (isPalindrome(head))
        printf("Linked list is a palindrome.\n");
    else
        printf("Linked list is not a palindrome.\n");
}