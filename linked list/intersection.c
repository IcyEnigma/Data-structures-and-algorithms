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
// Function to sort linked list
void sort_list(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        struct node *temp1=temp->next;
        while(temp1!=NULL){
            if(temp->data>temp1->data){
                int temp_data=temp->data;
                temp->data=temp1->data;
                temp1->data=temp_data;
            }
            temp1=temp1->next;
        }
        temp=temp->next;
    }
}

int main(){
    int n1,n2,maxIntersection,i;
    printf("Enter the number of nodes in the first linked list: ");
    scanf("%d",&n1);
    struct node *head1=create_list(n1);
    printf("\nEnter the number of nodes in the second linked list: ");
    scanf("%d",&n2);
    struct node *head2=create_list(n2);
    sort_list(head1);
    sort_list(head2);
    // By this point, two linked lists have been created and sorted
    // Now, we need to find the intersection of the two lists
    if(n1>n2){
        maxIntersection=n2;
    }
    else{
        maxIntersection=n1;
    }
    i=0;
    int arr[maxIntersection];
    struct node *ptr1=head1;
    struct node *ptr2=head2;
    while(ptr1 && ptr2){
        if(ptr1->data==ptr2->data){
            arr[i]=ptr1->data;
            i++;
        }
        if(ptr1->data<ptr2->data){
            ptr1=ptr1->next;
        }
        else{
            ptr2=ptr2->next;
        }
    }
    printf("\nThe intersection of the two linked lists is: ");
    for(int j=0;j<i;j++){
        printf("%d ",arr[j]);
    }
    return 0;
}
