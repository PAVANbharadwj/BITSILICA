#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
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
    return head;
}

void printList(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int getLength(node* head)
{
    int count = 0;
    while (head != NULL) 
    {
        count++;
        head = head->next;
    }
    return count;
}
node* findIntersection(node* head1, node* head2)
{
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    int diff = abs(len1 - len2);

        if (len1 > len2)
    {
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    } 
    else
     {
        for (int i = 0; i < diff; i++)
            head2 = head2->next;
    }
       while (head1 && head2)
        {
         if (head1 == head2)
                return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
    return NULL;
}
int main() 
{
    node *head1 = NULL, *head2 = NULL;
    int n1, n2, data;

    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head1 = insertEnd(head1, data);
    }

    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) 
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head2 = insertEnd(head2, data);
    }

    if (head1 && head2) 
    {
        node* temp1 = head1;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        node* temp2 = head2;
        while (temp2->next != NULL)
            temp2 = temp2->next;
        temp2->next = head1->next;
    }

    printf("\nList 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);

    node* inter = findIntersection(head1, head2);
    if (inter)
        printf("\nIntersection found at node with data: %d\n", inter->data);
    else
        printf("\nNo intersection found.\n");

    return 0;
}