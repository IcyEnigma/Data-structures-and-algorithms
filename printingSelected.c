#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

// Function to create a linked list and return head
struct node *create_list(int n){
        struct node *head=NULL,*tail=NULL;
    int i, data;
    for(i=1;i<=n;i++){
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data for node %d: ",i);
        scanf("%d",&data);
        temp->data=data;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    return head;
}

int main(){
    int ln,pn;
    printf("Enter the length of the list L : ");
    scanf("%d",&ln);
    struct node *Lhead=create_list(ln);
    printf("Enter the length of the list P : ");
    scanf("%d",&pn);
    struct node *Phead=create_list(pn);
    struct node *Lptr=Lhead;
    struct node *Pptr=Phead;
    while(Pptr){
        Lptr = Lhead;
        for(int i=1;i<Pptr->data;i++){
            if(Lptr==NULL){
                printf("\nIndex out of range");
            }
            else{
                Lptr=Lptr->next;
            }
        }
        if(Lptr==NULL){
            printf("\nIndex out of range");
        }
        else{
            printf("\n%d",Lptr->data);
        }
        Pptr=Pptr->next;
    }
    return 0;
}
