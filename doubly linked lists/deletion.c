#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head=NULL;
    struct node *temp=NULL;
    int n, data, del;
    scanf("%d", &n);
    temp = head;
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            newnode->prev=NULL;
        }
        else{
            newnode->prev=temp;
            temp->next=newnode;
        }
        temp=newnode;
    }

    scanf("%d", &del);
    if(del>n){
        temp=head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
        }
        return 0;
    }
    temp=head;
    for(int i=1;i<del;i++){
        temp=temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    temp=head;
    while(temp){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    return 0;
}