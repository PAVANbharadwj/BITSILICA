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
int loopLength(struct node *head)
{
    struct node *slow = head, *fast = head;

    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) 
        {
            int count = 1;
            struct node *temp = slow->next;
            while (temp != slow)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }

    return 0;
}
int main()
{
    struct node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    head->next->next->next->next->next = head->next->next;
    int len = loopLength(head);
    if (len)
        printf("Loop detected of length = %d\n", len);
    else
        printf("No loop found\n");
}
