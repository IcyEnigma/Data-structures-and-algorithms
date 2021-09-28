#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int pid;
    int block;
    struct node *next;
};
int search(struct node *head, int x)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->pid == x)
            return 1;
        current = current->next;
    }
    return 0;
}
int count(struct node *head, int x)
{
    struct node *current = head;
    int c = 0;
    while (current != NULL)
    {
        if (current->pid == x)
            return c;

        c++;

        current = current->next;
    }
    return 0;
}
void insertAtBeginning(struct node **ref, int data)
{
    // Allocate memory to a node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    // insert the item
    new_node->pid = data;
    new_node->next = (*ref);
    // Move head to new node
    (*ref) = new_node;
}
void insertAfter(struct node *head, int pos, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    int i;
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->pid = data;
        temp = head;
        for (i = 0; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
    }
}
void insertAtEnd(struct node **ref, int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *ref;
    new_node->pid = data;
    new_node->next = NULL;
    if (*ref == NULL)
    {
        *ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}


void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->pid);
        head = head->next;
    }
}
int main()
{
    int c = 0;
    char ch[10], ch2[10];
    int p, b, p1, b1, ps, pos;
    struct node *head;
    struct node *first = (struct node *)malloc(sizeof(struct node));
    //printf("Enter PID : ");
    scanf("%d", &p);
    //printf("Enter Blocks : ");
    scanf("%d", &b);
    first->pid = p;
    first->block = b;
    first->next = NULL;
    head = first;
    //display(head);
    //printf("\n");
    while (c == 0)
    {
        //printf("\nDo you want to insert another node(y/n) : ");
        scanf("%s", ch);
        if (strcmp(ch, "y") == 0)
        {
            //printf("Enter PID : ");
            scanf("%d", &p1);
            //printf("Enter Blocks : ");
            scanf("%d", &b1);
            //printf("Enter pid search : ");
            scanf("%d", &ps);
            scanf("%s", ch2);
            if (search(head, ps) == 1) //If search succeeds
            {
                //printf("Insert After/Before (a/b) : ");
                if (strcmp(ch2, "a") == 0)
                {
                    pos = count(head, ps);
                    //printf("\nPosition is : %d\n",pos);
                    insertAfter(head, pos, p1);
                }
                else
                {
                    pos = count(head, ps);
                    //printf("\nPosition is : %d\n",pos-1);
                    if (pos - 1 < 0)
                    {
                        insertAtBeginning(&head, p1);
                    }
                    else
                    {
                        insertAfter(head, pos - 1, p1);
                    }
                }
        }
        else
        {
            insertAtEnd(&head, p1);
        }
        //display(head);
        //printf("\n");
    }
    else
    {
        c++;
    }
}
display(head);
return 0;
}