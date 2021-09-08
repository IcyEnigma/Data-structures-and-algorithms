#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node* reverse(struct node *head){
struct node *prev,*next,*curr;
prev = NULL;
next = NULL;
curr = head;
while(curr){
next = curr->next;
curr->next = prev;
prev = curr;
curr = next;
}
return prev;
}

void print(struct node *head){
struct node *curr;
curr = head;
while(curr){
printf("%d ",curr->data);
curr = curr->next;
}
printf("\n");
}

int main(){
int n, data;
scanf("%d",&n);
struct node *head = NULL, *temp, *newnode;
while(n--){
newnode = (struct node*)malloc(sizeof(struct node));
scanf("%d",&data);
newnode->data = data;
newnode->next = NULL;
if(head == NULL){
head = newnode;
temp = head;
}
else{
temp->next = newnode;
temp = temp->next;
}
}
print(head);
temp = reverse(head);
print(temp);

}
