#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head=NULL,*tail,*newnode;
    int n,i,data;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
        }
        tail=newnode;
    }
    scanf("%d",&i);
    switch(i){
        case 1:{
            head->next->prev=NULL;
            head=head->next;
            break;
        }
        case 2:{
            int index;
            scanf("%d",&index);
            struct node *temp=head;
            for(i=0;i<index-1;i++){
                temp = temp->next;
            }
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                free(temp);
            break;
        }
        case 3:{
            tail->prev->next=NULL;
            tail=tail->prev;
            break;
        }
        default: printf("Invalid choice!");
        break;
    }
    struct node *temp=head;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}