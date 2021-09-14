#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main(){
    int n, data, i;
    struct node *head1=NULL, *temp1, *head2=NULL, *temp2, *newnode;
    scanf("%d", &n);
    for(i = 0; i <= n; i++){
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if(head1 == NULL){
            head1 = newnode;
            temp1 = head1;
        }
        else{
            temp1->next = newnode;
            temp1 = temp1->next;
        }
    }
    for(i = 0; i <= n; i++){
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if(head2 == NULL){
            head2 = newnode;
            temp2 = head2;
        }
        else{
            temp2->next = newnode;
            temp2 = temp2->next;
        }
    }
    temp1 = head1;
    temp2 = head2;
    while(temp1){
        printf("+%dX^%d", temp1->data + temp2->data, n--);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}