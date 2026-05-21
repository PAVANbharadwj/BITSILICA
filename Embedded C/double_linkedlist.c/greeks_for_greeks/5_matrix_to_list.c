#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* matrixToList(int rows, int cols, int mat[rows][cols])
{
    struct Node *head = NULL, *tail = NULL;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            struct Node* newNode = createNode(mat[i][j]);
            if (head == NULL)
                head = tail = newNode;
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }
    return head;
}

void printList(struct Node* head)
{
    while (head) 
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    struct Node* list = matrixToList(2, 3, mat);
    printList(list);
}
