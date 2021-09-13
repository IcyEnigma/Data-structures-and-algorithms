#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head=NULL, *temp=NULL;
    struct node *newnode;
    int n,pos,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
        }
        temp=newnode;
    }
    scanf("%d",&pos);
    switch(pos)
    {
        case 1:{
            newnode=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&newnode->data);
            newnode->next=head;
            newnode->prev=NULL;
            head->prev=newnode;
            head=newnode;
            break;
        }
        case 2:{
            scanf("%d",&i);
            i--;
            newnode=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&newnode->data);
            struct node *temp1=head;
            while(i--){
                temp1=temp1->next;
            }
            newnode->next=temp1;
            newnode->prev=temp1->prev;
            temp1->prev->next=newnode;
            temp1->prev=newnode;
            break;
        }
        case 3:{
            newnode=(struct node*)malloc(sizeof(struct node));
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            newnode->prev=temp;
            temp->next=newnode;
            temp=newnode;
            break;
        }

    }
    struct node *temp2=head;
    while(temp2!=NULL){
        printf("%d ",temp2->data);
        temp2=temp2->next;
    }
    return 0;
}   