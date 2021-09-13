#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
    int n, data, ch;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
        }
        temp = newnode;
    }
    temp->next = head;
    head->prev = temp;
    scanf("%d", &ch);
    switch (ch)
    {
        case 1:
        {
            int ins;
            scanf("%d", &ins);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = ins;
            newnode->next = head;
            head->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            head = newnode;
            break;
        }
        case 2:
        {
            int index;
            int ins;
            scanf("%d", &index);
            scanf("%d", &ins);
            struct node *temp1 = head;
            for (int i = 1; i < index; i++)
            {
                temp1 = temp1->next;
            }
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = ins;
            newnode->next = temp1;
            newnode->prev = temp1->prev;
            temp1->prev->next = newnode;
            temp1->prev = newnode;
            break;
        }
        case 3:
        {
            int ins;
            scanf("%d", &ins);
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = ins;
            newnode->next = head;
            head->prev = newnode;
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    struct node *ptr = head;
    printf("%d ", ptr->data);
    ptr = ptr->next;
    while (ptr != head)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return 0;
}