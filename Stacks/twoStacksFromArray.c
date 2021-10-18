#include<stdio.h>
//make two stacks from a single array//
int main(){
    int arr[100],top1=-1,top2=50,i,temp, s1, s2;
    printf("Enter no of elements to push to stack 1: ");
    scanf("%d", &s1);
    for(i=0;i<s1;i++){
        printf("\nEnter element to push to stack 1: ");
        scanf("%d", &arr[i]);
        top1++;
    }
    printf("\nEnter no of elements to push to stack 2: ");
    scanf("%d", &s2);
    for(i=1;i<s2+1;i++){
        printf("\nEnter element to push to stack 2: ");
        scanf("%d", &arr[50+i]);
        top2++;
    }

    printf("\nElements in stack 1: ");
    for(i=0;i<s1;i++){
        printf("%d ", arr[i]);
    }
    printf("\n Top of stack 1 is %d, top element is %d", top1, arr[top1]);

    printf("\nElements in stack 2: ");
    for(i=50;i<top2+1;i++){
        printf("%d ", arr[i]);
    }
    printf("\n Top of stack 2 is %d, top element is %d\n", top2, arr[top2]);

}