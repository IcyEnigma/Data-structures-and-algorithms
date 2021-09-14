#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int main(){
    int n;
    scanf("%d", &n);
    struct node *head, *temp, *newnode;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    int data;
    scanf("%d", &data);
    head->data = data;
    temp = head;
    for(int i=1;i<n;i++){
        scanf("%d",&data);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = newnode;
    }
    int index;
    if(n%2==1){
        index = (n/2)+1;
        temp = head;
        for(int i=1;i<index;i++){
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}
