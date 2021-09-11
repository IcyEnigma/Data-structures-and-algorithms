#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main(){
    struct node *head=NULL;
    struct node *ptr1=NULL;
    struct node *ptr2=NULL;
    int n,data;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d : ",i+1);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            ptr1=newnode;
        }
        else{
            ptr1->next=newnode;
            ptr1=newnode;
        }
    }
    ptr1=head;
    int maxCount = 0, curr, count, maxElement;
    while(ptr1){
        ptr2 = head;
        curr = ptr1->data;
        count = 0;
        while(ptr2){
            if(ptr2->data == curr){
                count++;
            }
            ptr2 = ptr2->next;
        }
        if(count > maxCount){
            maxCount = count;
            maxElement = curr;
        }
        ptr1 = ptr1->next;
    }
    if(maxCount > n/2){
        printf("Majority element is %d",maxElement);
    }
    else{
        printf("No majority element");
    }
    return 0;
}
