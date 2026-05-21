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

    if (!head)
        return new;

    node* temp = head;
    while (temp->next)
        temp = temp->next;
    
    temp->next = new;
    return head;
}

void printlist(node* head)
{
    printf("\nList: ");
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

node* reverse(node* head) 
{
    node *prev = NULL, *curr = head, *next = NULL;

    while (curr) 
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int isPalindrome(node* head) 
{
    if (!head || !head->next)
        return 1;

    node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

        slow = reverse(slow);

    node* first = head;
    node* second = slow;

    while (second)
    {
        if (first->data != second->data)
            return 0; 
        first = first->next;
        second = second->next;
    }

    return 1;
}

int main() 
{
    int n;
    node* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        head = createnode(head);

    printlist(head);

    if (isPalindrome(head))
        printf("\nThe linked list is a PALINDROME.\n");
    else
        printf("\nThe linked list is NOT a palindrome.\n");

    return 0;
}