#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* createNode(int data) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void convertToDLL(Node* root, Node** head, Node** prev) 
{
    if (root == NULL)
        return;

    convertToDLL(root->left, head, prev);

    if (*prev == NULL)
        *head = root;    
    else
    {
        root->left = *prev; 
        (*prev)->right = root; 
    }
    *prev = root; 

    convertToDLL(root->right, head, prev);
}

void printDLL(Node* head) 
{
    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->right;
    }
    printf("\n");
}

int main() 
{
    Node* root = createNode(10);
    root->left = createNode(6);
    root->right = createNode(14);
    root->left->left = createNode(4);
    root->left->right = createNode(8);
    root->right->left = createNode(12);
    root->right->right = createNode(16);

    Node* head = NULL;
    Node* prev = NULL;

    convertToDLL(root, &head, &prev);

    printDLL(head);
}