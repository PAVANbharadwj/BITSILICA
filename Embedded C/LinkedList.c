/*
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node* createnode(int data){
    struct node* newnode =(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insert(struct node **head,int data){
    struct node* newnode=createnode(data);
    if(*head==NULL){
        *head=newnode;
    return;
    }
    struct node*temp=*head;
    while(temp->next)
        temp=temp->next;
    temp->next=newnode;
}

struct node* merg(struct node* l1, struct node* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    if(l1->data<l2->data){
        l1->next=merg(l1->next,l2);
        return l1;
    }
    else{
        l2->next=merg(l1,l2->next);
        return l2;
    }
}

void print(struct node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

int main() {
    struct node *list1 = NULL, *list2 = NULL;
    int n1, n2, value;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter %d sorted elements for List 1:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insert(&list1, value);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter %d sorted elements for List 2:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insert(&list2, value);
    }

    struct node* merged = merg(list1, list2);
    printf("Merged list: ");
    print(merged);
    return 0;
}
*/