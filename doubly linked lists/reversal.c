#include <stdio.h> 
#include <stdlib.h> 

struct Node 
{ 
  int data; 
  struct Node *next; 
  struct Node *prev;     
}; 
void reverse(struct Node **head_ref);
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node); 


/* Function to reverse the linked list */
void reverse(struct Node **head_ref){
      struct Node* prev = NULL;
  struct Node* current = *head_ref;
  struct Node* next;
  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head_ref = prev;
}


void push(struct Node** head_ref, int new_data){
      struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = new_data;
  new_node->next = (*head_ref);
  new_node->prev = NULL;
  if((*head_ref) != NULL){
    (*head_ref)->prev = new_node;
  }
  (*head_ref) = new_node;
}


void printList(struct Node *node){
  while(node != NULL){
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}
int main(){
  struct Node* head = NULL;
  int a,b,c,d,e;
  scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    push(&head, a);
    push(&head, b);
    push(&head, c);
    push(&head, d);
    push(&head, e);
  printList(head);
  reverse(&head);
  printList(head);
  return 0;
}

