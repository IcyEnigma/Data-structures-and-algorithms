#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head=NULL, *temp, *newnode;
    int n,data,ch;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&data);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
            newnode->prev=temp;
        }
        temp=newnode;
    }
    temp->next=head;
    head->prev=temp;
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:{
       temp->next = head->next;
       head->next->prev = temp;
       free(head);
       head = temp->next;
        break;
    }
    case 2:{
        int index;
        scanf("%d",&index);
        struct node *temp1=head;
        for(int i=0;i<index;i++){
            temp1=temp1->next;
        }
        temp1->prev->next=temp1->next;
        temp1->next->prev=temp1->prev;
        free(temp1);
        break;
    }
    case 3:{
        temp->prev->next=head;
        head->prev=temp->prev;
        free(temp);
        temp = head->prev;
    }
    
    default: printf("Invalid choice! ");
        break;
    }
    struct node *ptr = head;
    printf("%d ",ptr->data);
    ptr = ptr->next;
    while(ptr!=head){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}