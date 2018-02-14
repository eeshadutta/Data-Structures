#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *top = NULL;

void push()
{
    stack *temp = (stack *)malloc(sizeof(stack));
    scanf("%d", &temp->data);
    temp->next = top;
    top = temp;
    return;
}

void pop()
{
    stack *temp = top;
    if (temp == NULL)
    {
        printf("Underflow\n");
        return;
    }
    else
    {
        top = top->next;
    }
    printf("Deleted Value: %d\n", temp->data);
    free(temp);
    return;
}

void print()
{
    for (stack *temp = top; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
    return;
}

int main()
{
    int flag;
    printf("0)Exit 1)Push 2)Pop 3)Print\n");
    scanf("%d", &flag);
    while (flag)
    {
        if (flag == 1)
        {
            push();
        }
        else if (flag == 2)
        {
            pop();
        }
        else if (flag == 3)
        {
            print();
        }
        printf("0)Exit 1)Push 2)Pop 3)Print\n");
        scanf("%d", &flag);
    }
    return 0;
}