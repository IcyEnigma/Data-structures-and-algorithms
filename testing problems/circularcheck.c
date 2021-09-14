#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

void checkCircular(struct node *head){
    struct node *temp;
    temp = head;
    while(temp->next != NULL){
        if(temp->next == head){
            printf("Yes\n");
            return;
        }
        temp = temp->next;
    }
    printf("No\n");
}

int main(){
    struct node *head = NULL, *temp, *newnode;
    for(int i = 1; i < 5; i++){
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = i;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = head;
        }
        else{
            temp->next = newnode;
            temp = temp->next;
        }
    }
    checkCircular(head);
    temp->next = head;
    checkCircular(head);
}