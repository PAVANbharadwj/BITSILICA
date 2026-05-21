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

node* insertEnd(node* head) 
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

node* deleteNode(node* head) 
{
    if (head == NULL)
     {
        printf("List is empty.\n");
        return head;
    }

    int value;
    printf("Enter value to delete: ");
    scanf("%d", &value);

    if (head->data == value)
    {
        node* temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted.\n");
        return head;
    }

    node* prev = head;
    node* curr = head->next;

    while (curr != NULL && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Value not found.\n");
        return head;
    }

    prev->next = curr->next;
    free(curr);
    printf("Node deleted.\n");

    return head;
}

void traverse(node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    node* head = NULL;
    int choice;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node\n");
        printf("3. Traverse / Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = insertEnd(head);
                break;
            case 2:
                head = deleteNode(head);
                break;
            case 3:
                traverse(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
