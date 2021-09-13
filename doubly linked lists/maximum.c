#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

int main(){
    struct node *head = NULL;
    struct node *tail = NULL;
    struct node *temp = NULL;
    int i, n, max = 0;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        temp = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &temp->data);
        if(head == NULL){
            head = temp;
            tail = temp;
            temp->next = NULL;
            temp->prev = NULL;
        }
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
            temp->prev = NULL;
        }
    }
    temp = head;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    printf("%d", max);
    return 0;
}