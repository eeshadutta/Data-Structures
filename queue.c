#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
} queue;

queue *front = NULL;
queue *end = NULL;

void enqueue()
{
    queue *temp = (queue *)malloc(sizeof(queue));
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (front == NULL)
    {
        front = temp;
        end = temp;
    }
    else
    {
        end->next = temp;
        end = temp;
    }
    return;
}

void dequeue()
{
    queue *temp = front;
    if (temp == NULL)
    {
        printf("Underflow\n");
        return;
    }
    front = front->next;
    free(temp);
    return;
}

void print()
{
    for (queue *temp = front; temp != NULL; temp = temp->next)
    {
        printf("%d ", temp->data);
    }
    printf("\n");
    return;
}

int main()
{
    int flag;
    printf("0)Exit 1)Enqueue 2)Dequeue 3)Print\n");
    scanf("%d", &flag);
    while (flag != 0)
    {
        if (flag == 1)
        {
            enqueue();
        }
        else if (flag == 2)
        {
            dequeue();
        }
        else if (flag == 3)
        {
            print();
        }
        printf("0)Exit 1)Enqueue 2)Dequeue 3)Print\n");
        scanf("%d", &flag);
    }
    return 0;
}