#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *reverse(struct node *head)
{
    struct node *previous = NULL;
    struct node *current = head;
    while (current)
    {
        struct node *next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    return previous;
}
int main()
{
    struct node
        *p,
        *head, *nextnode, *current, *next, *rev, *revprev, *revend, *revendnext;
    head = NULL;
    rev = NULL;
    revprev = NULL;
    revendnext = NULL;
    p = head;
    int l, m, n, r = 0;
    scanf("%d", &l);
    for (int i = 0; i < l; i++)
    {
        nextnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &(nextnode->data));
        if (head == NULL)
            head = nextnode;
        else
            p->next = nextnode;
        p = nextnode;
    }
    scanf("%d %d ", &m, &n);
    current = head;
    int i = 1;
    while (current && i <= n)
    {
        if (i < m)
            revprev = current;
        if (i == m)
            rev = current;
        if (i == n)
        {
            revend = current;
            revendnext = current->next;
        }
        current = current->next;
        i++;
    }
    revend->next = NULL;
    revend = reverse(rev);
    if (revprev)
        revprev->next = revend;
    else
        head = revend;
    rev->next = revendnext;
    p = head;
    for (int i = 0; i < l; i++)
    {
        printf("%d ", p->data);
        p = p->next;
    }