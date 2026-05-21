#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int val;
    struct Node* next;
} Node;

Node* newNode(int val) 
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    return node;
}

void printList(Node* head)
{
    while(head)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int cmp(const void* a, const void* b) 
{
    return (*(int*)a - *(int*)b);
}

Node* mergeAndSortLists(Node* lists[], int k) 
{
    int total = 0;
    for(int i=0; i<k; i++) {
        Node* temp = lists[i];
        while(temp) {
            total++;
            temp = temp->next;
        }
    }

    int* arr = (int*)malloc(sizeof(int)*total);
    int idx = 0;
    for(int i=0; i<k; i++) {
        Node* temp = lists[i];
        while(temp) {
            arr[idx++] = temp->val;
            temp = temp->next;
        }
    }

    qsort(arr, total, sizeof(int), cmp);

    Node dummy;
    Node* tail = &dummy;
    dummy.next = NULL;
    for(int i=0; i<total; i++) {
        tail->next = newNode(arr[i]);
        tail = tail->next;
    }

    free(arr);
    return dummy.next;
}

int main() 
{
    int k = 3;

    Node* list1 = newNode(7); list1->next = newNode(1); list1->next->next = newNode(4);
    Node* list2 = newNode(8); list2->next = newNode(2); list2->next->next = newNode(5);
    Node* list3 = newNode(6); list3->next = newNode(3); list3->next->next = newNode(9);

    Node* lists[] = {list1, list2, list3};

    Node* merged = mergeAndSortLists(lists, k);
    printf("Merged and Sorted List: ");
    printList(merged);
}