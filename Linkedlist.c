//Linked list program in c (one way)
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void traverse(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("Null\n");
}

int main(){
    struct Node* head=createNode(10);
    struct Node* second=createNode(20);
    struct Node* third=createNode(30);

    //link nodes
    head->next=second;
    second->next=third;

    //traverse list
    printf("Linkedlist:");
    traverse(head);

    return 0;
}